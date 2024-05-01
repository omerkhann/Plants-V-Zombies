#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
#include"Plants.h"
using namespace std;
using namespace sf;


//SunFlower "is-a" plant
class SunFlower : public Plant {

private:
	const int plantPrice;

public:

	//Constructor
	SunFlower();

	//No getters, setters needed. Cost is a constant. 

	//Other Member Functions

	void produceSun();
	void destroySelf();
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
};


SunFlower::SunFlower() : plantPrice(100), Plant() {
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/SunFlower.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/SunFlower.png" << endl;
	}
	plantSprite.setTexture(texture);
}

void SunFlower::produceSun() {

	return;
}

void SunFlower::destroySelf() {
	return;
}

void SunFlower::setPosition(float x, float y) {
	plantSprite.setPosition(x, y);
}

void SunFlower::draw(RenderWindow& window) {
	window.draw(plantSprite);
}