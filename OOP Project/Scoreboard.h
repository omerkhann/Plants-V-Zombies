#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Scoreboard {
private:
    int score;
    Texture boardTex;
    Sprite board;
    Font boardFont;
    Text scoreText;

public:
    // Constructor
    Scoreboard();

    // Getter/Setter
    int getScore();
    void setScore(int);

    // Other Member Functions
    void addToScore(int);
    void drawBoard(RenderWindow&);
};

// Constructor
Scoreboard::Scoreboard() : score(0) {
    if (!boardTex.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Images/board.jpg")) {
        cerr << "Error loading board texture" << endl;
    }
    board.setTexture(boardTex);
    board.setPosition(1200 - 125, 0);  // Positioned in the top right corner

    if (!boardFont.loadFromFile("C:/Users/DELL/source/repos/OOP Project/Fonts/arial.otf")) {
        cerr << "Failed to load font" << endl;
    }

    scoreText.setFont(boardFont);
    scoreText.setCharacterSize(24); // Set the font size
    scoreText.setFillColor(Color::Red); // Set the text color
    scoreText.setPosition(1075, 100); // Adjusted position to be on the board
    scoreText.setString("SCORE: " + to_string(score)); // Set the initial score
}

// Getter/Setter
int Scoreboard::getScore() { return score; }
void Scoreboard::setScore(int input) {
    score = input;
    scoreText.setString("Score: " + to_string(score));
}

void Scoreboard::addToScore(int add) {
    score += add;
    scoreText.setString("Score: " + to_string(score));
}

void Scoreboard::drawBoard(RenderWindow& window) {
    window.draw(board);
    window.draw(scoreText);
}