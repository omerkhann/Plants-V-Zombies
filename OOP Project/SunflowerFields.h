#pragma once
#include"Level.h"
#include<iostream>
using namespace std;



class SunflowerFields : public Level {


public:

	virtual void drawLevel(RenderWindow&);
	
};


void SunflowerFields::drawLevel(RenderWindow& window) {

	//Image map_image;
	//map_image.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/Frontyard.png");
	//Texture map;
	//map.loadFromImage(map_image);
	//Sprite s_map;
	//s_map.setTexture(map);
	//s_map.setPosition(0, 0);
	//window.draw(s_map);

	lvlImage.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/Frontyard.png");
	lvlTex.loadFromImage(lvlImage);
	lvlSprite.setTexture(lvlTex);
	window.draw(lvlSprite);
}