#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Sun {

private:
	Sprite sunSprite;
	Texture sunTex;
	
	float fallSpeed;
	float posX;
	float posY;
	
	bool limitCheck;
	bool collected;
	
	Clock fallClock;

public:

	// Constructors
	Sun();
	Sun(float, float);
	
	// Getters
	// Setters

	// Other Member Functions
	void draw(RenderWindow&);
	bool checker();
	void sunFall();
	void beCollected();
	void update(RenderWindow&, Vector2i);
};


// Default
Sun::Sun() :fallSpeed(20.0f), posX(0), posY(-100), limitCheck(false), collected(false) {
	if (!sunTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/sun.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/sun.png" << endl;
	}
	else {
		//IntRect sunRect(0, 0, 25, 25);
		sunSprite.setTexture(sunTex);
		//sunSprite.setTextureRect(sunRect);
		sunSprite.setPosition(posX, posY);

		// Randomizing x-coord of each object
		srand(time(0));
		int min = 400;
		int max = 1000;
		float random_posX = min + rand()%(max - min + 1);
		posX = random_posX;

	}
}

// Parameterized
Sun::Sun(float posx, float posy) :fallSpeed(0), posX(posx), posY(posy+35), limitCheck(false), collected(false) {
	if (!sunTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/sun.png")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/sun.png" << endl;
	}
	else {
		sunSprite.setTexture(sunTex);
		sunSprite.setPosition(posX, posY);
	}
}


// Other Member Functions

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