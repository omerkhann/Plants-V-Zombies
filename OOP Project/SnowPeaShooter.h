#pragma once
#include"ShootingPlant.h"

class SnowPeaShooter : public ShootingPlant {

public:

	// Constructor
	SnowPeaShooter();

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
	//virtual void shootPea(RenderWindow&);
};



SnowPeaShooter::SnowPeaShooter(): ShootingPlant(200)
{
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/peashooter.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/peashooter.png" << endl;
	}
	plantSprite.setTexture(texture);
}


void SnowPeaShooter::setPosition(float x, float y) {
	plantSprite.setPosition(x, y);
}

void SnowPeaShooter::draw(RenderWindow& window) {
	window.draw(plantSprite);
}