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
	Level(int);

	//Getters
	PlantFactory& getPlantFactory();

	// Setters


	// Other Member Functions
	virtual void drawLevel(RenderWindow&) = 0; // Purely virtual. Each level will have different backgrounds to load, different buttons to show. 
	

	void handlePlantSelection(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant); 
	void handlePlantPlacement(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant);
	
	virtual void drawPlants(RenderWindow& window) { plantFactory.drawPlant(window); }
	void drawLawnMowers(RenderWindow&);

	coordinates approximateCoords(float, float);

};




// Constructors
Level::Level(int level = 0) : levelNumber(level){}

// Getters
PlantFactory& Level::getPlantFactory() {
	return plantFactory;
}

// Setters


// Other Member Functions
void Level::handlePlantSelection(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		// Assuming these are your plant button positions and sizes
		sf::FloatRect sunflowerButtonRect(0, 0, 107, 67);
		sf::FloatRect peaShooterButtonRect(0, 68, 107, 67);

		if (sunflowerButtonRect.contains(mousePos.x, mousePos.y)) {
			delete selectedPlant; 
			selectedPlant = new SunFlower(); 
			currentState = GameState::PlacingPlant;
		}
		else if (peaShooterButtonRect.contains(mousePos.x, mousePos.y)) {
			delete selectedPlant; 
			selectedPlant = new PeaShooter();
			currentState = GameState::PlacingPlant;
		}
	}
}


void Level::handlePlantPlacement(RenderWindow& window, const sf::Event& event, GameState& currentState, Plant*& selectedPlant) {
	if (currentState == GameState::PlacingPlant && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		coordinates mousepos = approximateCoords(mousePos.x, mousePos.y);
		//selectedPlant->setPosition(mousePos.x - 53, mousePos.y - 34); // Each sprite is about 107x68, so / 2
		selectedPlant->setPosition(mousepos.x, mousepos.y);
		plantFactory.addPlant(selectedPlant); 
		
		cout << "Plant placed at: " << mousePos.x << ", " << mousePos.y << endl;
		selectedPlant = nullptr;
		
		//Once plant is placed, GameState returns to SelectingPlant 
		currentState = GameState::SelectingPlant; 
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

coordinates Level::approximateCoords(float x, float y) {
	coordinates coord;

	// Grid starts at (395, 91) in window
	int gridStartX = 395;
	int gridStartY = 91;   

	int tileWidth = 100;  
	int tileHeight = 100;

	int col = (x - gridStartX) / tileWidth;
	int row = (y - gridStartY) / tileHeight;

	// Value clamping within grid of 5x9
	col = max(0, min(col, 8)); 
	row = max(0, min(row, 4));  

	coord.x = gridStartX + col * tileWidth - 20; //Offset of 20 for proper placement
	coord.y = gridStartY + row * tileHeight;

	return coord;
}