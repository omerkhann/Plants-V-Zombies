#pragma once
#include<iostream>
#include"Inventory.h"
#include"PlantFactory.h"
#include"Lawnmower.h"
#include"Sunflower.h"
#include"PeaShooter.h"
#include"CherryBomb.h"
#include"WallNut.h"
#include"Vector.h"
using namespace std;


class Level {

protected:
	
	int levelNumber;

	/*Inventory levelInventory;*/
	
	PlantFactory plantFactory;
	Image lvlImage;
	Texture lvlTex;
	Sprite lvlSprite;

public:
	
	// Constructors
	Level();
	Level(int);

	// Getters
	

	// Setters


	// Other Member Functions
	virtual void drawLevel(RenderWindow&) = 0; 
	
	virtual void handlePlantSelection(RenderWindow& window) = 0;
	virtual void handlePlantPlacement(RenderWindow& window) = 0;
	virtual void drawPlants(RenderWindow& window) { plantFactory.drawPlant(window); }

	void drawLawnMowers(RenderWindow&);

};

// Constructors
Level::Level() :levelNumber(0){}
Level::Level(int level) : levelNumber(level){}

// Getters


// Setters


// Other Member Functions
void Level::handlePlantPlacement(RenderWindow& window) {
	Event event;
	while (window.waitEvent(event)) {
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			coordinates mousePos = mousePos.convertToCoordinates(Mouse::getPosition(window));
			SunFlower* newSunflower = new SunFlower();
			newSunflower->setPosition(mousePos.x, mousePos.y);
			plantFactory.addPlant(newSunflower);  // Add to the plant factory
			break;
		}
	}
}

void Level::drawLawnMowers(RenderWindow& window) {
	

	LawnMower lawn1(300,120);
	LawnMower lawn2(300, 240);
	LawnMower lawn3(300, 340);
	LawnMower lawn4(300, 460);
	LawnMower lawn5(300, 580);
	
	lawn1.draw(window);
	lawn2.draw(window);
	lawn3.draw(window);
	lawn4.draw(window);
	lawn5.draw(window);
}
