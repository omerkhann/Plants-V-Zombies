#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Plant {

protected:
	int plantHealth;
	int numOfHits;
	Sprite plantSprite;
	Texture texture;
		
public:	

	//Constructor
	Plant();
	

	//Getters
	int getPlantHealth();
	int getNumHits();

	//Setters
	void setPlantHealth(int);
	void setNumHits(int);

	//Other Member Functions
	virtual void setPosition(float, float) = 0;
	virtual void draw(RenderWindow&) = 0;

};


Plant::Plant() :plantHealth(100), numOfHits(0) {}


//Getters
int Plant::getPlantHealth() {
	return plantHealth;
}
int Plant::getNumHits() {
	return numOfHits;
}

//Setters
void Plant::setPlantHealth(int health) {
	plantHealth = health;
}
void Plant::setNumHits(int hits) {
	numOfHits = hits;
}