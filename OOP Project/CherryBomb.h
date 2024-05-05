#pragma once
#include"Plant.h"

class CherryBomb : public Plant {

private:
	//const int plantPrice;

public:
	
	// Constructor
	CherryBomb();

	// Getter

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
	
	void explode();
	//bool zombieCollisionCheck();
};


CherryBomb::CherryBomb(): Plant(150){
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/cherrybomb.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/cherrybomb.png" << endl;
	}
	plantSprite.setTexture(texture);
}

void CherryBomb::setPosition(float x, float y) {
	posX = x;
	posY = y;
	plantSprite.setPosition(x, y);
}

void CherryBomb::draw(RenderWindow& window) {
	window.draw(plantSprite);
}

void CherryBomb::explode() {
	return;
}
