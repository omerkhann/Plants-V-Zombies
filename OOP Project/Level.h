#pragma once
#include<iostream>
#include"Inventory.h"
#include"PlantFactory.h"
using namespace std;


class Level {

private:
	int levelNumber;
	Inventory levelInventory;
	PlantFactory plantFac;

public:
	
	// Constructors
	Level();
	Level(int);

	// Getters
	

	// Setters


	// Other Member Functions
	//virtual void drawLevel(); 

};

// Constructors
Level::Level() :levelNumber(0){}
Level::Level(int level) : levelNumber(level){}


// Getters

// Setters

// Other Member Functions
//virtual void drawLevel();

