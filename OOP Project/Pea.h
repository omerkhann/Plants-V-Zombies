#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Pea {

private:
	Sprite peaSprite;
	Texture peaTex;
	
	float posX;
	float posY;
	
	int moveSpeed;

public:

	// Constructor
	Pea(float, float);
	
	//void setPosition(float, float);
	void movePea();
	void draw(RenderWindow&);
};

Pea::Pea(float posx, float posy):posX(posx + 60), posY(posy+10), moveSpeed(5) {
	if (!peaTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/pea.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/pea.png" << endl;
	}
	peaSprite.setTexture(peaTex);
	peaSprite.setPosition(posX, posY);
	//movePea();
}

void Pea::draw(RenderWindow& window) {
	window.draw(peaSprite);
}

void Pea::movePea() {
	posX += moveSpeed;
	peaSprite.setPosition(posX, posY);
}


