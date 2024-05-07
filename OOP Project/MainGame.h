#pragma once
#include<iostream>
#include"Level.h"
#include"Plant.h"
#include"PlantFactory.h"
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
	Level* getLvlPtr();

	//Setters
	void setLives(int);
	void setPlayerName(string);
	void setLvlPtr(Level*);
	//Other member functions
	
	//void runGameLoop()
	void createMap(RenderWindow& window);
	
	bool createMenuScreen(RenderWindow& window, const Font& font);
	void loadHighScores(RenderWindow&);
	void loadInstructions(RenderWindow&);


	//void showScoreBoard(RenderWindow&)
	//void loadEndScreen(RenderWindow&);
	//void loadPauseScreen(RenderWindow&);


};


// Constructor
MainGame::MainGame():playerName("X"), playerLives(3), currLevel(NULL){}

// Getters
int MainGame::getPlayerLives() {return playerLives;}
string MainGame::getPlayerName() {return playerName;}
Level* MainGame::getLvlPtr() { return currLevel; }

// Setters
void MainGame::setLives(int live) { playerLives = live; }
void MainGame::setPlayerName(string name) { playerName = name;}
void MainGame::setLvlPtr(Level* setPtr) { currLevel = setPtr; }


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

	Text instrucButton("INSTRUCTIONS", font, 50);
	instrucButton.setFillColor(Color::Green);
	instrucButton.setPosition(650, 300);
	window.draw(instrucButton);

	// Calculate button dimensions
	string scoreButtonText = scoreButton.getString();
	double scoreButtonWidth = scoreButtonText.length() * scoreButton.getCharacterSize() * 0.6;
	double scoreButtonHeight = scoreButton.getCharacterSize() * 1.2;

	string startButtonText = startButton.getString();
	double startButtonWidth = startButtonText.length() * startButton.getCharacterSize() * 0.6;
	double startButtonHeight = startButton.getCharacterSize() * 1.2;

	string instrucButtonText = instrucButton.getString();
	double instrucButtonTextWidth = instrucButtonText.length() * instrucButton.getCharacterSize() * 0.6;
	double instrucButtonTextHeight = instrucButton.getCharacterSize() * 1.2;

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
			if (mousePos.x >= instrucButton.getPosition().x && mousePos.x <= instrucButton.getPosition().x + instrucButtonTextWidth &&
				mousePos.y >= instrucButton.getPosition().y && mousePos.y <= instrucButton.getPosition().y + instrucButtonTextHeight) {
				loadInstructions(window);
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
	Texture texture;
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/finishscreen.png")) {
		cerr << "Error loading finish screen image" << endl;
		return;
	}
	Sprite newbg(texture);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				return; // Returns to main menu
			}
		}

		window.clear();
		window.draw(newbg);
		window.display();
	}
}

void MainGame::loadInstructions(RenderWindow& window) {
	Texture texture;
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/finishscreen.png")) {
		cerr << "Error loading finish screen image" << endl;
		return;
	}
	Sprite newbg(texture);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				return;  // Returns to main menu
			}
		}

		window.clear();
		window.draw(newbg);
		window.display();
	}
}

