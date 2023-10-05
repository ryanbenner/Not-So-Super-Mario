/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class creates the world, all the levels, and moves mario throughout the world
*/

#include "Level.h"
#include "Game.h"
#include "World.h"
#include "Mario.h"
#include <string>
#include <fstream>

World::World() {
}

World::World(int levels, int gridSize, string items, int lives, string file) {
    L = levels;
    N = gridSize;
    mW_items = items;
    mW_currentLevel = 0;
    mW_movesTaken = 0;
    mW_gameOver = false;
    fileName = file;
    mW_world = new char**[L]; // LxNxN array of chars (world)
    mW_Level = new Level(N, mW_items, file);
    mW_Mario = new Mario(N, L, lives, file);
    srand(static_cast<int>(time(0))); // random seed generator
}

World::~World() {
}

void World::setLevel(int i) { // sets current level
    mW_Level->assignLevel(mW_world[i]);
}

void World::locateMario() { // finds mario in the grid
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
        for (int j = 0; j < N; j++) {
            if (mW_Level->getGrid()[i][j] == 'H') {
                mW_Mario->setRow(i);
                mW_Mario->setCol(j);
                mW_Mario->setObj('x');
                found = true;
                break;
            }
        }
    }
    string input = "Mario is starting in position: (" + std::to_string(mW_Mario->getRow()) + ", " + std::to_string(mW_Mario->getCol()) + ")\n";
    fileOutput(input);
}

void World::generateWorld() { // creates the world
    for (int i = 0; i < L; i++) {
        mW_world[i] = new char*[N];
        for (int j = 0; j < N; j++) {
            mW_world[i][j] = new char[N];
        }
    }

    int x;
    for (int i = 0; i < L; i++) {
        x = 0; // to iterate through mW_items

        // easy way to rearrange array/string efficiently
        unsigned num = chrono::system_clock::now().time_since_epoch().count();
	    shuffle(mW_items.begin(), mW_items.end(), default_random_engine(num));

        // set world indexes to mW_items randomized item list 
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                mW_world[i][j][k] = mW_items[x];
                char c = mW_world[i][j][k];
                std::string input(1, c);
                fileOutput(input + " ");
                x++;
            }
            fileOutput("\n");
        }
        fileOutput("=========\n");
    }
    generateLevel();
}

void World::generateLevel() { // sets up the level
    setLevel(mW_currentLevel);
    if (mW_currentLevel != L - 1) { // no warp on last level
        mW_Level->placeWarpPipe();
    }
    mW_Level->placeBoss();
    mW_Level->placeMario();
    locateMario();
    mW_Level->printGrid();
}

void World::moveMario() { // moves mario
    while (mW_Mario->getLives() > 0 && !mW_gameOver) 
    {
        rowOrCol = rand() % 2;
        plusOrMinus = rand() % 2;

        string input = "Current Level: " + std::to_string(mW_currentLevel) + "\n";
        fileOutput(input);
        input = "Mario is at position: (" + std::to_string(mW_Mario->getRow()) + ", " + std::to_string(mW_Mario->getCol()) + ")" + "\n";
        fileOutput(input);
        input = "Mario is at power level " + std::to_string(mW_Mario->getPwrLvl()) + "." + "\n";
        fileOutput(input);
        
        // check for warp pipe or boss
        if (mW_Mario->getObj() == 'w' || 'B') {
            bossOrWarp(); // bossOrWarp includes content in else{}, but w/ extra steps
        }
        else {
            input = mW_Mario->whatHappened() + "\n"; // checks outcome of mario interaction with what he's standing on (from previous turn)
            fileOutput(input);
            input =  "Mario has " + std::to_string(mW_Mario->getLives()) + " lives left." + "\n";
            fileOutput(input);
            input = "Mario has " + std::to_string(mW_Mario->getCoins()) + " coins." + "\n";
            fileOutput(input);
            mW_Level->setGrid(mW_Mario->getRow(), mW_Mario->getCol(), mW_Mario->getObj()); // mario will 'leave behind' either an x,k,g,B based on outcome.
        }

        // move mario truth table
        if (mW_Mario->getLives() > 0 && !mW_gameOver) { // if mario has lives, and hasn't beaten the final boss
            if (rowOrCol == 0 && plusOrMinus == 0) {
                if (mW_Mario->getRow() == 0) {
                    mW_Mario->setRow(N - 1);
                }
                else {
                    mW_Mario->setRow(mW_Mario->getRow() - 1);
                }
                fileOutput("Mario will move UP\n");
            }
            else if (rowOrCol == 0 && plusOrMinus == 1) {
                if (mW_Mario->getRow() == N - 1) {
                    mW_Mario->setRow(0);
                }
                else {
                    mW_Mario->setRow(mW_Mario->getRow() + 1);
                }
                fileOutput("Mario will move DOWN.\n");
            }
            else if (rowOrCol == 1 && plusOrMinus == 0) {
                if (mW_Mario->getCol() == 0) {
                    mW_Mario->setCol(N - 1);
                }
                else {
                    mW_Mario->setCol(mW_Mario->getCol() - 1);
                }
                fileOutput("Mario will move LEFT.\n");
            }
            else if (rowOrCol == 1 && plusOrMinus == 1) {
                if (mW_Mario->getCol() == N - 1) {
                    mW_Mario->setCol(0);
                }
                else {
                    mW_Mario->setCol(mW_Mario->getCol() + 1);
                }
                fileOutput("Mario will move RIGHT.\n");
            }

            // set the object mario is 'standing on' (temp obj: x,g,k,B)
            mW_Mario->setObj(mW_Level->getGrid()[mW_Mario->getRow()][mW_Mario->getCol()]);
            // set the square mario is on to 'H'
            mW_Level->setGrid(mW_Mario->getRow(), mW_Mario->getCol(), 'H');
            mW_Level->printGrid();
            mW_movesTaken++;
        }
    }
}

void World::bossOrWarp() { // if mario is on a boss or warp pipe, handles outcome
    // check what happened on square mario is on
    fileOutput(mW_Mario->whatHappened() + "\n");
    fileOutput("Mario has " + std::to_string(mW_Mario->getLives()) + " lives left.\n");
    fileOutput("Mario has " + std::to_string(mW_Mario->getCoins()) + " coins.\n");
    // checks if he beat a boss and isn't on final level, or if he took a warp
    if ((mW_Mario->getBoss() == true && mW_currentLevel !=2) || mW_Mario->getObj() == 'w') {
        mW_currentLevel++;
        generateLevel();
        mW_Mario->setObj('x');
        mW_Mario->setBoss(false);
    }
    // checks if he beat final boss
    else if (mW_Mario->getBoss() == true && mW_currentLevel == 2) {
            mW_gameOver = true;
        }
    mW_Level->setGrid(mW_Mario->getRow(), mW_Mario->getCol(), mW_Mario->getObj());
}

bool World::gameOver() { // checks if the game is over
    if (mW_Mario->getLives() == 0) {
        fileOutput("Mario is out of lives! You lose!\n");
        fileOutput("Moves taken: " + std::to_string(mW_movesTaken) + "\n");
        fileOutput("GAME OVER\n");
        fileOutput("=========\n");
        return true;
    }
    else if (mW_gameOver) {
        fileOutput("Mario defeated the final boss! You win!\n");
        fileOutput("Moves taken: " + std::to_string(mW_movesTaken) + "\n");
        fileOutput("GAME COMPLETE\n");
        fileOutput("=========\n");
        return true;
    }
}

void World::fileOutput(string input) { // outputs to output.txt
    ofstream outputFile;
    outputFile.open(fileName, std::ios_base::app);
    outputFile << input;
}

