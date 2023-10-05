#ifndef LEVEL_H
#define LEVEL_H

#include "Game.h"
/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class handles logic for the current level, such as placing mario, WP, and the boss
*/

#include "World.h"
#include "Mario.h"

class Level: public World {
    public:
        Level(); // constructor
        Level(int gridSize, string items, string file); // oload constructor
        virtual ~Level(); // destructor

        void printGrid(); // prints the grid
        void deleteGrid(); // deletes the grid
        void placeMario(); // places mario in level
        void placeWarpPipe(); // places warp pipe in level
        void placeBoss(); // places boss in level
        void assignLevel(char** grid) { array = grid; }; // sets the current 'level' grid from the world grid
        char** getGrid() { return array; }; // allows access to level grid
        void setGrid(int i, int j, char element); // sets a posiiton on the grid to an element
        void fileOutput(string input); // outputs to the file

    private:
        int mL_gridSize; // size of level grid
        string mL_items; // string of all items to be placed in level
        string fileName; // name of output file
        char** array; // current level grid

};

#endif