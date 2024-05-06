// Our own coordinate-keeping 

#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>
#include<vector>
using namespace std;
using namespace sf;

struct coordinates {
	float x;
	float y;

	coordinates convertToCoordinates(const Vector2i& vec) {
		return { static_cast<float>(vec.x), static_cast<float>(vec.y) };
	}

};


enum class GameState {
	SelectingPlant,
	PlacingPlant
};