#pragma once
#include"Level.h"
#include<iostream>
using namespace std;


class BeginnersGarden : public Level {


public:

	// Constructor
	BeginnersGarden(int);

	// Other Member Functions
	virtual void drawLevel(RenderWindow&);
};


// Constructor
BeginnersGarden::BeginnersGarden(int level = 1) :Level(level){}

// Other Member Functions
void BeginnersGarden::drawLevel(RenderWindow& window) {

	lvlImage.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/Frontyard.png");
	lvlTex.loadFromImage(lvlImage);
	lvlSprite.setTexture(lvlTex);
	lvlSprite.setPosition(0, 0);
	window.draw(lvlSprite);


	sf::Texture sFbuttonTex;
	sf::Sprite sFbutton;
	sFbuttonTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/sunflowerCard.png");
	sFbutton.setTexture(sFbuttonTex);
	sFbutton.setPosition(0, 0);


	sf::Texture peabuttontex;
	sf::Sprite PSbutton;
	peabuttontex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/peashooterCard.png");
	PSbutton.setTexture(peabuttontex);
	PSbutton.setPosition(0, 68);

	sf::Texture cherryTex;
	sf::Sprite CBbutton;
	cherryTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/cherrybombunav.png");
	CBbutton.setTexture(cherryTex);
	CBbutton.setPosition(0, 136);

	sf::Texture wallnutTex;
	sf::Sprite WNbutton;
	wallnutTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/wallnutunav.png");
	WNbutton.setTexture(wallnutTex);
	WNbutton.setPosition(0, 200);


	window.draw(sFbutton);
	window.draw(PSbutton);
	window.draw(CBbutton);
	window.draw(WNbutton);

}

