#pragma once
#include"ShootingPlant.h"


class PeaShooter : public ShootingPlant {

private:
	const int plantPrice;

public:
	
	// Constructor
	PeaShooter();

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
};


PeaShooter::PeaShooter():plantPrice(100), ShootingPlant() 
{
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/peashooter.gif")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/peashooter.gif" << endl;
	}
	plantSprite.setTexture(texture);
}

void PeaShooter::setPosition(float x, float y) {
	plantSprite.setPosition(x, y);
}

void PeaShooter::draw(RenderWindow& window) {
	window.draw(plantSprite);
}