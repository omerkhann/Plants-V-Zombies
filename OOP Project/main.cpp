#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<ctime>
#include<vector>
#include"MainGame.h"
#include"Sunflower.h"
#include"PeaShooter.h"
#include"Plant.h"
#include"Sun.h"
#include"Lawnmower.h"
#include"Vector.h"
using namespace sf;
using namespace std;


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


	// Main Game declaration
	MainGame game;

	// Display the first screen and wait for the user to start the game
	bool startGame = false;
	while (!startGame && window.isOpen()) {
		startGame = game.createMenuScreen(window, font);
		sf::sleep(sf::milliseconds(100)); // Sleep to reduce CPU usage
	}

	Music.stop();


	// INSTRUCTIONS SCREEN //
	//game.createIntstructionScreen(window)

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
		game.createBack(window);
		game.createMap(window);
		//window.setSize(sf::Vector2u(550, 340));
		//window.setSize(sf::Vector2u(750, 540));
		window.setSize(sf::Vector2u(1200, 700));
		
		
		SunFlower.draw(window);
		SunFlower.setPosition(400, 140);
		SunFlower.update(window);

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