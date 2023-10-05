/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class creates the world, all the levels, and moves mario throughout the world
*/

#ifndef WORLD_H
#define WORLD_H

#include "Game.h"

#include <string>

using namespace std;
class Level; // circular dependencies of classes, declare before initialization
class Mario;
class WarpPipe;

class World {
    public:
        World(); // constructor
        World(int levels, int gridSize, string items, int lives, string file); // oload constructor
        virtual ~World(); // destructor

        void generateWorld(); // creates the world
        void generateLevel(); // sets up the level
        void moveMario(); // moves mario
        void locateMario(); // finds mario's position in the level
        void setLevel(int i); // sets the current level
        void bossOrWarp(); // handles logic if mario is on boss or warp pipe
        bool gameOver();  // checks if game is over 
        void fileOutput(string input); // prints output to output.txt

    private:
        int rowOrCol; // determines if mario will move along row or col, 0 or 1
        int plusOrMinus; // determines if marios row/col will decrease or increase, 0 or 1
        int mW_currentLevel; // current level
        int L; // number of levels
        int N; // grid size
        int mW_movesTaken; // num moves taken
        bool mW_gameOver; // checks if game is over
        string mW_items; // list of items occupying grid spaces
        Mario* mW_Mario; // mario
        Level* mW_Level; // level
        char*** mW_world; // LxNxN array
        string fileName; // output.txt
};

#endif