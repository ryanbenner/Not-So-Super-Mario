/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class handles logic for the current level, such as placing mario, WP, and the boss
*/

#include "Level.h"
#include "Game.h"
#include "World.h"
#include <fstream>

#include <string>


Level::Level() {
}

Level::Level(int gridSize, string items, string file) {
    mL_gridSize = gridSize;
    mL_items = items;
    fileName = file;
}

Level::~Level() {
}

void Level::printGrid() { // prints out the current level
    fileOutput("=========\n");
    for (int i = 0; i < mL_gridSize; i++) {
        for (int j = 0; j < mL_gridSize; j++) {
            char c = array[i][j];
            std::string input(1,c);
            fileOutput(input + " ");
        }
        fileOutput("\n");
    }
    fileOutput("=========\n");
}

void Level::deleteGrid() { // deletes current level
    for (int i = 0; i < mL_gridSize; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void Level::placeMario() { // places mario somewhere in the level randomly
    int row = rand() % mL_gridSize;
    int col = rand() % mL_gridSize;

    char temp;

    if (array[row][col] == 'x') {
        array[row][col] = 'H';
    }
    else if (array[row][col] != 'x') {
        temp = array[row][col];
        array[row][col] = 'H';

        bool found = false;

        for (int i = 0; i < mL_gridSize && !found; i++) {
            for (int j = 0; j < mL_gridSize; j++) {
                if (array[i][j] == 'x') {
                    array[i][j] = temp;
                    temp = ' ';
                    found = true;
                    break;
                }
            }
        }
    }
}

void Level::placeWarpPipe() { // places warp pipe in the level randomly
    int row = rand() % mL_gridSize;
    int col = rand() % mL_gridSize;

    char temp;

    if (array[row][col] == 'x') {
        array[row][col] = 'w';
    }
    else if (array[row][col] != 'x') {
        temp = array[row][col];
        array[row][col] = 'w';

        bool found = false;

        for (int i = 0; i < mL_gridSize && !found; i++) {
            for (int j = 0; j < mL_gridSize; j++) {
                if (array[i][j] == 'x') {
                    array[i][j] = temp;
                    temp = ' ';
                    found = true;
                    break;
                }
            }
        }
    }
    fileOutput("Placing WarpPipe at (" + std::to_string(row) + ", " + std::to_string(col) + ")" + "\n");
}

void Level::placeBoss() { // places boss in the level randomly
    int row = rand() % mL_gridSize;
    int col = rand() % mL_gridSize;

    char temp;

    if (array[row][col] == 'x') {
        array[row][col] = 'B';
    }
    else if (array[row][col] != 'x') {
        temp = array[row][col];
        array[row][col] = 'B';

        bool found = false;

        for (int i = 0; i < mL_gridSize && !found; i++) {
            for (int j = 0; j < mL_gridSize; j++) {
                if (array[i][j] == 'x') {
                    array[i][j] = temp;
                    temp = ' ';
                    found = true;
                    break;
                }
            }
        }
    }
    fileOutput("Placing Bowser at (" + std::to_string(row) + ", " + std::to_string(col) + ")" + "\n");
}

void Level::setGrid(int i, int j, char element) { // sets a current level grid element
    array[i][j] = element;
}

void Level::fileOutput(string input) { // function to output to the output.txt
    ofstream outputFile;
    outputFile.open(fileName, std::ios_base::app);
    outputFile << input;
}
