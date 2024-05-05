#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
#include"Plant.h"
using namespace std;

class PlantFactory {

private:
	Plant** ptr;
	int size;
	int current;

public:
	
	// Constructor
	PlantFactory(int);

	// Getters

	// Setters

	// Other Functions
	void addPlant(Plant*);
	void drawPlant(RenderWindow&);
	Plant* operator[](int);

	// Destructor
	~PlantFactory();

};


// Constructor
PlantFactory::PlantFactory(int size = 5) : size(size), current(0) 
{
	ptr = new Plant* [size];
}

// Getters

// Setters

// Other Functions
void PlantFactory::addPlant(Plant* plant) {
	if (plant != nullptr && current < size) {
		ptr[current] = plant;
		current++;
	}
}

void PlantFactory::drawPlant(RenderWindow& window) {
	for (int i = 0; i < current; ++i) {
		if (ptr[i] != nullptr) {
			ptr[i]->draw(window);
		}
	}
}

Plant* PlantFactory::operator[](int index) {
	if (index >= 0 && index < current) {
		return ptr[index];
	}
	else {
		return nullptr;
	}
}

// Destructor
PlantFactory::~PlantFactory() {
	for (int i = 0; i < size; i++) {
		delete ptr[i];
	}
	delete[]ptr;
}