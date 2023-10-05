/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is meant to initialize the game, run the gameplay loop, and initialize the world
*/

#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include "World.h"
#include "Mario.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <cstdlib>

class Game {
    public:
        Game(); // constructor
        Game(int coins, int mushrooms, int nothing, int goombas, int koopas, int numLevels, int gridSize, int lives, string fileName); // oload constructor
        ~Game(); // destructor

        void worldItems(); // creates a list of the required numbers of items in the world
        void runGame(); // runs the gameplay loop

        bool getGame() { return mG_gameOver; }; // returns whether the game is over

    protected:
        string items; // string of world items

    private:
        int mG_coins; // coins
        int mG_mushrooms; // mushrooms
        int mG_nothing; // nothing
        int mG_goombas; // goombas
        int mG_koopas; // koopas
        int mG_levels; // levels
        int mG_gridSize; // grid size
        bool mG_gameOver; // game over status
        World *mG_World; // world

};

#endif