#pragma once
#include<iostream>
#include"Level.h"
#include"Plant.h"
using namespace std;
using namespace sf;


class MainGame {
	
private:
	string playerName;
	int playerLives;
	Level* currLevel;

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
	bool createFirstScreen(RenderWindow& window, const Font& font);

	//void createLoadingScreen();
	//void createMainScreen();
	//void loadPauseScreen();
	//void loadHighScores();
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