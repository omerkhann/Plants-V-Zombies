#pragma once
#include"ShootingPlant.h"
#include"Pea.h"

class Repeater : public ShootingPlant {

private:
	//const int plantPrice;

public:

	// Constructor
	Repeater(RenderWindow&);

	//Getter
	int getPrice() const;

	// Other Member Functions
	virtual void setPosition(float, float);
	virtual void draw(RenderWindow&);
	virtual void shootPea(RenderWindow&);
};

Repeater::Repeater(RenderWindow& window): ShootingPlant(200)
{
	if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/repeater.gif")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/repeater.gif" << endl;
	}
	plantSprite.setTexture(texture);
	shootPea(window);
}

int Repeater::getPrice() const{
	return plantPrice;
}

void Repeater::setPosition(float x, float y) {
	plantSprite.setPosition(x, y);
}

void Repeater::draw(RenderWindow& window) {
	window.draw(plantSprite);
}

//void Repeater::shootPea(RenderWindow& window) {
//	Pea pea(posX,posY);
//}

void Repeater::shootPea(RenderWindow& window) {
	Pea pea(posX, posY);
	pea.draw(window);
	pea.movePea();
}
