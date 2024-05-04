#pragma once
#include<iostream>
#include"Plant.h"
using namespace std;
using namespace sf; 


// ShootingPlant "is-a" Plant
class ShootingPlant : public Plant {

protected:


public:

	// Constructor
	ShootingPlant();
	ShootingPlant(int);
	
	// Other Member Functions
	virtual void shootPea(RenderWindow&) = 0;

};


ShootingPlant::ShootingPlant() : Plant() {}
ShootingPlant::ShootingPlant(int price):Plant(price){}