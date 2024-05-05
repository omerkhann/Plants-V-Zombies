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
	virtual void handlePlantSelection(RenderWindow&);
	virtual void handlePlantPlacement(RenderWindow&);
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


	window.draw(sFbutton);
	window.draw(PSbutton);
}


void BeginnersGarden::handlePlantSelection(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			coordinates mousePos = mousePos.convertToCoordinates(Mouse::getPosition(window));
			// Example: Check if a specific plant button was clicked
			// This is where you would check button dimensions
			cout << "Plant type selected for placement" << endl;
		}
	}
}

void BeginnersGarden::handlePlantPlacement(RenderWindow& window) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			coordinates mousePos = mousePos.convertToCoordinates(Mouse::getPosition(window));
			Plant* newPlant = new SunFlower();  // Assuming selection logic is handled
			newPlant->setPosition(mousePos.x, mousePos.y);
			plantFactory.addPlant(newPlant);
			cout << "Plant placed at: " << mousePos.x << ", " << mousePos.y << endl;
		}
	}
}