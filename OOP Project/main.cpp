#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <ctime>
#include<vector>
#include"Sunflower.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;


//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/Frontyard.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
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


bool createFirstScreen(RenderWindow& window, const Font& font) {
	window.clear();

	// Background for the menu
	Texture texture;
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/firstscreen.png")) {
		cerr << "Error loading first screen image" << endl;
	}
	Sprite background(texture);

	// Start button
	Text startButton("Start Game", font, 50);
	startButton.setFillColor(Color::Green);
	startButton.setPosition(600, 300); // Adjust position based on your window size and preferences

	window.draw(background);
	window.draw(startButton);
	window.display();

	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				Vector2i mousePos = Mouse::getPosition(window);
				if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
					return true;  // Start the game if the button is clicked
				}
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
		startGame = createFirstScreen(window, font);
		sf::sleep(sf::milliseconds(100)); // Sleep to reduce CPU usage
	}

	Music.stop();

	Clock timeMoney;
	Clock clock;

	SunFlower myPlant;

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

		window.setSize(sf::Vector2u(550, 340));
		myPlant.draw(window);
		myPlant.setPosition(400, 140);

		window.display();
	}
	return 0;
}