#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include<iostream>
using namespace std;
using namespace sf;

class LawnMower{

private:
	Sprite mowerSprite;
	Texture mowerTex;

	bool zombieReached;

	float posX;
	float posY;

	const int moveSpeed;

public:

	// Constructor
	LawnMower(float, float);

	// Getter
	bool getZombieReached();	

	// Other Member Functions
	void setPosition(float, float);
	void draw(RenderWindow&);
	void move();
	//bool zombieCollisionCheck();   // AA BB COLLISION CHECK
};


LawnMower::LawnMower(float posx, float posy):posX(posx), posY(posy), zombieReached(false), moveSpeed(10.0f){

	if (!mowerTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/lawnmower.gif")) {
		cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/lawnmower.gif" << endl;
	}
	mowerSprite.setTexture(mowerTex);
	setPosition(posX, posY);
}

bool LawnMower::getZombieReached() {
	return zombieReached;
}

void LawnMower::setPosition(float x, float y) {
	posX = x;
	posY = y;
	mowerSprite.setPosition(x, y);
}

void LawnMower::draw(RenderWindow& window) {
	window.draw(mowerSprite);
}

void LawnMower::move() {
	
	const int xLimit = 1300;
	if (zombieReached)
	{
		posX += moveSpeed;
		setPosition(posX, posY);
	}
}
