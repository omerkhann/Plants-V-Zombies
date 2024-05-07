#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
#include"Plant.h"
#include"Sun.h"
using namespace std;
using namespace sf;


// SunFlower "is-a" plant
class SunFlower : public Plant {

private:
	Clock sunProductionTime;

public:

	// Constructor
	SunFlower();

	// Other Member Functions
	void makeSun(RenderWindow&);
	void destroySelf();
	void update(RenderWindow&);
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
};

// Constructor
SunFlower::SunFlower() : Plant(100) 
{
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/SunFlower.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/SunFlower.png" << endl;
	}
	plantSprite.setTexture(texture);
}


// Other Member Functions
void SunFlower::update(RenderWindow& window) {
	if (sunProductionTime.getElapsedTime().asSeconds() == 10) {
		makeSun(window);
		sunProductionTime.restart();
	}
}

void SunFlower::makeSun(RenderWindow& window) {

	Sun producedSun(posX, posY);
	producedSun.draw(window);
}

void SunFlower::destroySelf() {
	return;
}

void SunFlower::setPosition(float x, float y) {
	posX = x;
	posY = y;
	plantSprite.setPosition(x, y);
}

void SunFlower::draw(RenderWindow& window) {
	window.draw(plantSprite);
	update(window);
}