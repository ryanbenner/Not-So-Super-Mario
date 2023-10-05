/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is meant to initialize the game, run the gameplay loop, and initialize the world
*/

#include "Level.h"
#include "Game.h"
#include "World.h"
#include "FileProcessor.h"

Game::Game() {
    mG_coins = 0;
    mG_mushrooms = 0;
    mG_nothing = 0;
    mG_goombas = 0;
    mG_koopas = 0;
    mG_levels = 0;
    mG_gridSize = 0;
}

Game::Game(int coins, int mushrooms, int nothing, int goombas, int koopas, int numLevels, int gridSize, int lives, string fileName) {
    mG_coins = coins;
    mG_mushrooms = mushrooms;
    mG_nothing = nothing;
    mG_goombas = goombas;
    mG_koopas = koopas;
    mG_levels = numLevels;
    mG_gridSize = gridSize;
    worldItems();
    mG_World = new World(mG_levels, mG_gridSize, items, lives, fileName);
    ofstream outputFile(fileName);
}

Game::~Game(){
    delete mG_World;
}

void Game::worldItems() {
    // concatenates all items together
    items = string(mG_coins, 'c') + string(mG_mushrooms, 'm') + string(mG_nothing, 'x') + string(mG_goombas, 'g') + string(mG_koopas, 'k');
}

void Game::runGame() { // gameplay loop here
    mG_World->generateWorld();  
    while (!mG_gameOver) {
        mG_World->moveMario(); 
        if (mG_World->gameOver()) {
            mG_gameOver = true;
        }
    }
}