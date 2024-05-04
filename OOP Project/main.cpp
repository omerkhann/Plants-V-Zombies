#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <ctime>
#include<vector>
#include"Sunflower.h"
#include"PeaShooter.h"
#include"Repeater.h"
#include"Plant.h"
#include"Sun.h"
#include"Lawnmower.h"

using namespace sf;
using namespace std;


struct coordinates {
	float x;
	float y;

	coordinates convertToCoordinates(const Vector2i& vec) {
		return { static_cast<float>(vec.x), static_cast<float>(vec.y) };
	}

};


// Drawing the background
void createBack(RenderWindow& window) {

	Image map_image;
	map_image.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/Frontyard.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);


	sf::Texture sFbuttonTex;
	sf::Sprite sFbutton;
	sFbuttonTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/img1.png");
	sFbutton.setTexture(sFbuttonTex);
	sFbutton.setPosition(0, 0)	;

	sf::Texture peabuttontex;
	sf::Sprite PSbutton;
	peabuttontex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/img3.png");
	PSbutton.setTexture(peabuttontex);
	PSbutton.setPosition(0, 68);

	sf::Texture RPbuttontex;
	sf::Sprite RPbutton;
	RPbuttontex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/img4.png");
	RPbutton.setTexture(sFbuttonTex);
	RPbutton.setPosition(0, 136);

	window.draw(sFbutton);
	window.draw(PSbutton);
	window.draw(RPbutton);

}

// Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;
	map_image.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/grid.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(395, 130);

	window.draw(s_map);
}

// Menu Screen Creation
bool createMenuScreen(RenderWindow& window, const Font& font) {
	window.clear();

	// Load and display the menu background
	Texture texture;
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/menuscreen_edited.jpg")) {
		cerr << "Error loading first screen image" << endl;
		return false;
	}
	Sprite background(texture);
	window.draw(background);

	// Setup and display the start button
	Text startButton("Start Game", font, 50);
	startButton.setFillColor(Color::Green);
	startButton.setPosition(500, 500); // Adjust position based on your window size and preferences
	window.draw(startButton);
	window.display();

	// Manually calculate button dimensions
	string buttonText = startButton.getString();
	float buttonWidth = buttonText.length() * startButton.getCharacterSize() * 0.6; // Approximation
	float buttonHeight = startButton.getCharacterSize() * 1.2; // Approximation

	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			coordinates mousePos = mousePos.convertToCoordinates(Mouse::getPosition(window));
			// Manually checking if the click is within the bounds of the start button
			if (mousePos.x >= startButton.getPosition().x && mousePos.x <= startButton.getPosition().x + buttonWidth &&
				mousePos.y >= startButton.getPosition().y && mousePos.y <= startButton.getPosition().y + buttonHeight) {
				return true;  // Start the game if button clicked
			}
		}
	}

	return false;
}


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	
	//Game icon
	Image icon;
	if (!icon.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
    		for (int j = 0; j < COLS; j++) {
        		FIELD_GAME_STATUS[i][j] = true;
    		}
	}


	// Load font
	Font font;
	if (!font.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Fonts/arial.otf")) {
		cerr << "Failed to load font" << endl;
		return 1;
	}

	// Initializing Background Music.
	sf::Music Music;
	Music.openFromFile("C:/Users/DELL/source/repos/OOP Project/Audios/bgmusic2.mp3");
	Music.play();
	Music.setVolume(50);


	// Display the first screen and wait for the user to start the game
	bool startGame = false;
	while (!startGame && window.isOpen()) {
		startGame = createMenuScreen(window, font);
		sf::sleep(sf::milliseconds(100)); // Sleep to reduce CPU usage
	}

	Music.stop();

	Clock timeMoney;
	Clock clock;

	SunFlower SunFlower;
	PeaShooter a;
	Sun sun;

	LawnMower lawn1(300,140);
	LawnMower lawn2(300, 240);
	LawnMower lawn3(300, 340);
	LawnMower lawn4(300, 440);
	LawnMower lawn5(300, 540);

	//Initializing Background Music
	sf::Music bgMusic;
	bgMusic.openFromFile("C:/Users/DELL/source/repos/OOP Project/Audios/bgmusic.mp3");
	bgMusic.play();
	bgMusic.setVolume(50);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//Create a background
		createBack(window);
		createMap(window);
		//window.setSize(sf::Vector2u(550, 340));
		//window.setSize(sf::Vector2u(750, 540));
		window.setSize(sf::Vector2u(1200, 700));
		
		
		SunFlower.draw(window);
		SunFlower.setPosition(400, 140);
		
		a.draw(window);
		a.setPosition(500, 140);
		a.shootPea(window);
		
		sun.draw(window);
		sun.sunFall();

		lawn1.draw(window);
		lawn2.draw(window);
		lawn3.draw(window);
		lawn4.draw(window);
		lawn5.draw(window);

		lawn1.move();

		window.display();
	}
	return 0;
}