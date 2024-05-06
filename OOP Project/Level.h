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
	
	void handlePlantSelection(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant);
	void handlePlantPlacement(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant);
	virtual void drawPlants(RenderWindow& window) { plantFactory.drawPlant(window); }

	void drawLawnMowers(RenderWindow&);

};

// Constructors
Level::Level() :levelNumber(0){}
Level::Level(int level) : levelNumber(level){}

// Getters


// Setters


// Other Member Functions
void Level::handlePlantSelection(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		// Assuming these are your plant button positions and sizes
		sf::FloatRect sunflowerButtonRect(0, 0, 107, 67);
		sf::FloatRect peaShooterButtonRect(0, 68, 107, 67);

		if (sunflowerButtonRect.contains(mousePos.x, mousePos.y)) {
			delete selectedPlant; // Safely delete the previous plant
			selectedPlant = new SunFlower();  // Managing memory
			currentState = GameState::PlacingPlant;
		}
		else if (peaShooterButtonRect.contains(mousePos.x, mousePos.y)) {
			delete selectedPlant; // Safely delete the previous plant
			selectedPlant = new PeaShooter();
			currentState = GameState::PlacingPlant;
		}
	}
}


void Level::handlePlantPlacement(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant) {
	if (currentState == GameState::PlacingPlant && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		selectedPlant->setPosition(mousePos.x, mousePos.y);
		plantFactory.addPlant(selectedPlant); // Add plant to the plant factory
		cout << "Plant placed at: " << mousePos.x << ", " << mousePos.y << endl;
		currentState = GameState::SelectingPlant; // Reset state to allow for new plant selection
		selectedPlant = nullptr; // Reset selected plant
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
