#pragma once
#include<iostream>
#include"Level.h"
#include"Plant.h"
#include"Vector.h"
#include"Scoreboard.h"
using namespace std;
using namespace sf;


class MainGame {
	
private:
	string playerName;
	int playerLives;
	Level* currLevel;
	Scoreboard scoreBoard;

public:
	
	//Constructors
	MainGame();

	//Getters
	string getPlayerName();
	int getPlayerLives();

	//Setters
	void setPlayerName(string);

	//Other member functions
	
	//void runGameLoop()
	void createBack(RenderWindow& window);
	void createMap(RenderWindow& window);
	
	bool createMenuScreen(RenderWindow& window, const Font& font);
	//void loadPauseScreen();
	void loadHighScores(RenderWindow&);
	//void loadEndScreen();

};


// Constructor
MainGame::MainGame():playerName("X"), playerLives(3), currLevel(NULL){}

// Getters
int MainGame::getPlayerLives() {
	return playerLives;
}

string MainGame::getPlayerName() {
	return playerName;
}

// Setters
void MainGame::setPlayerName(string name) {
	playerName = name;
}



// Drawing the background
void MainGame::createBack(RenderWindow& window) {

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
	sFbutton.setPosition(0, 0);

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
void MainGame::createMap(RenderWindow& window) {
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


// Main Menu Creation
bool MainGame::createMenuScreen(RenderWindow& window, const Font& font) {
	window.clear();

	// Load and display the menu background
	Texture texture;
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/menuscreen_edited.jpg")) {
		cerr << "Error loading first screen image" << endl;
		return false;
	}
	Sprite background(texture);
	window.draw(background);

	// Setup and display buttons
	Text scoreButton("HIGH SCORES", font, 50);
	scoreButton.setFillColor(Color::Green);
	scoreButton.setPosition(650, 400);
	window.draw(scoreButton);

	Text startButton("START GAME", font, 50);
	startButton.setFillColor(Color::Green);
	startButton.setPosition(650, 500);
	window.draw(startButton);

	// Calculate button dimensions
	string scoreButtonText = scoreButton.getString();
	double scoreButtonWidth = scoreButtonText.length() * scoreButton.getCharacterSize() * 0.6;
	double scoreButtonHeight = scoreButton.getCharacterSize() * 1.2;

	string startButtonText = startButton.getString();
	double startButtonWidth = startButtonText.length() * startButton.getCharacterSize() * 0.6;
	double startButtonHeight = startButton.getCharacterSize() * 1.2;

	window.display();

	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			coordinates mousePos = mousePos.convertToCoordinates(Mouse::getPosition(window));
			if (mousePos.x >= scoreButton.getPosition().x && mousePos.x <= scoreButton.getPosition().x + scoreButtonWidth &&
				mousePos.y >= scoreButton.getPosition().y && mousePos.y <= scoreButton.getPosition().y + scoreButtonHeight) {
				loadHighScores(window);
			}
			if (mousePos.x >= startButton.getPosition().x && mousePos.x <= startButton.getPosition().x + startButtonWidth &&
				mousePos.y >= startButton.getPosition().y && mousePos.y <= startButton.getPosition().y + startButtonHeight) {
				return true; 
			}
		}
	}

	return false;
}


void MainGame::loadHighScores(RenderWindow& window) {
	return;
}