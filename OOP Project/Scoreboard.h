#pragma once
#include<iostream>
using namespace std;


class Scoreboard {

private:
	int score;

public:
	
	// Constructor
	Scoreboard();

	// Getter/Setter
	int getScore();
	void setScore(int);
	
	// Other Member Functions
	void addToScore(int);
	//void drawBoard(RenderWindow&);

};

// Constructor
Scoreboard::Scoreboard() :score(0){}


// Getter/Setter
int Scoreboard::getScore() { return score; }
void Scoreboard::setScore(int input) { score = input; }

// Other Member Functions
void Scoreboard::addToScore(int add) { score += add; }
