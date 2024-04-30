#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Plant {

	int plantHealth;
	Sprite plantSprite;
	Texture texture;
		
public:	
	Plant():plantHealth(100){
		if (!texture.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/sunflower.gif")) {
			std::cerr << "Failed to load texture: " << "C:/Users/DELL/source/repos/OOP Project/Images/sunflower.gif" << std::endl;
		}
		plantSprite.setTexture(texture);
	}
	
	void setPosition(float x, float y) { plantSprite.setPosition(x, y); }

	void draw(RenderWindow& window) {
		window.draw(plantSprite);
	}

};