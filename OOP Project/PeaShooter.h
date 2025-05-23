#pragma once
#include"ShootingPlant.h"
#include"Pea.h"


class PeaShooter : public ShootingPlant {

private:

public:
	
	// Constructor
	PeaShooter();

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
	virtual void shootPea(RenderWindow&);
	void update(RenderWindow&);
};


PeaShooter::PeaShooter(): ShootingPlant(100) 
{
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/peashooter.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/peashooter.png" << endl;
	}
	plantSprite.setTexture(texture);
}

void PeaShooter::setPosition(float x, float y) {
	posX = x;
	posY = y;
	plantSprite.setPosition(x, y);
}

void PeaShooter::draw(RenderWindow& window) {
	window.draw(plantSprite);
	shootPea(window);
}

void PeaShooter::shootPea(RenderWindow& window) {
	Pea pea(posX, posY);
	pea.draw(window);
	pea.movePea();
}

void PeaShooter::update(RenderWindow& window) {
	shootPea(window);
}
