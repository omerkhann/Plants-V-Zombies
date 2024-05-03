#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Sun {

private:
	Sprite sunSprite;
	Texture sunTex;
	
	int fallSpeed;
	float posX;
	float posY;
	
	bool limitCheck;
	bool collected;
	
	Clock fallClock;

public:

	// Constructor
	Sun();
	
	// Getters
	// Setters

	// Other Member Functions
	void draw(RenderWindow&);
	bool checker();
	void sunFall();
	void beCollected();
	void update(RenderWindow&, Vector2i);
};


Sun::Sun() :fallSpeed(20.0f), posX(300), posY(-100), limitCheck(false), collected(false) {
	if (!sunTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/sun.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/sun.png" << endl;
	}
	else {
		//IntRect sunRect(0, 0, 25, 25);
		sunSprite.setTexture(sunTex);
		//sunSprite.setTextureRect(sunRect);
		sunSprite.setPosition(posX, posY);
	}
}

void Sun::draw(RenderWindow& window) {
	if(!collected){
	window.draw(sunSprite);
	}
}

bool Sun::checker() {
	return (posY >= 350);
}

//void Sun::sunFall() {
//	if (!checker()) {
//		posY += fallSpeed;  // Move the sun down
//		sunSprite.setPosition(posX, posY);
//	}
//}

void Sun::sunFall() {
	if (fallClock.getElapsedTime().asSeconds() > 10 && !collected) {  // Fall every 10 seconds
		if (!checker()) {
			posY += fallSpeed;  // Move the sun down
			sunSprite.setPosition(posX, posY);
		}
	}
}

void Sun::beCollected() {
	collected = false;  // Make the sun invisible
	posY = -50;       // Move off-screen
	sunSprite.setPosition(posX, posY);
	fallClock.restart();  // Restart the timer after collection
}

void Sun::update(RenderWindow& window, Vector2i mousePos) {
	if (sunSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		beCollected();
	}
	sunFall();
	draw(window);
}