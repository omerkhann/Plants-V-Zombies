#pragma once
#pragma once
#include"Plant.h"

class WallNut : public Plant {

private:

public:

	// Constructor
	WallNut();

	// Getter

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);

	//bool zombieCollisionCheck();
};


WallNut::WallNut() : Plant(50) {
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/wallnut.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/wallnut.png" << endl;
	}
	plantSprite.setTexture(texture);
}

void WallNut::setPosition(float x, float y) {
	posX = x;
	posY = y;
	plantSprite.setPosition(x, y);
}

void WallNut::draw(RenderWindow& window) {
	window.draw(plantSprite);
}
