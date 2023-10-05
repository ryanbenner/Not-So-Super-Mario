/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is to handle what happens in marios move, such as whether he wins or loses against an enemy
*/

#include "Mario.h"
#include <fstream>

Mario::Mario(int gridSize, int levels, int lives, string file) {
    mM_levels = levels;
    mM_gridSize = gridSize;
    mM_numLives = lives;
    mM_powerLevel = 0;
    mM_currentLevel = 0;
    mM_numCoins = 0;
    mM_bossDefeated = false;
    mM_finalBossDefeated = false;
    mM_enemiesDefeated = 0;
    fileName = file;
}

Mario::~Mario() {
}

string Mario::whatHappened() { // checks what object mario is 'standing on' and handles it
    switch (mM_gridObject) { 
        case 'x':
        {
            mM_gridObject = 'x';
            return "Mario visited an empty square.";
            break;
        }
        case 'm':
        {
            if (mM_powerLevel < 2) {
                mM_powerLevel++;
            }
            mM_gridObject = 'x';
            return "Mario ate a mushroom.";
            break;
        }
        case 'c':
        {
            mM_numCoins++;
            mM_gridObject = 'x';
            return "Mario got a coin.";
            break;
        }
        case 'g':
        {
            int randy = rand() % 100;
            if (randy > 80) {
                if (mM_powerLevel == 0) {
                    mM_numLives--;
                } 
                else {
                    mM_powerLevel--;
                }
                mM_gridObject = 'g';
                return "Mario encountered a goomba and lost.";
                break;
            }
            else {
                mM_enemiesDefeated++;
                mM_gridObject = 'x';
                return "Mario encountered a goomba and won.";
            }
            break;
        }
        case 'k':
        {
            int randy = rand() % 100;
            if (randy > 65) {
                if (mM_powerLevel == 0) {
                    mM_numLives--;
                } 
                else {
                    mM_powerLevel--;
                }
                mM_gridObject = 'k';
                return "Mario encountered a koopa and lost.";
                break;
            }
            else {
                mM_enemiesDefeated++;
                mM_gridObject = 'x';
                return "Mario encountered a koopa and won.";
            }
            break;
        }
        case 'H':
        {
            mM_gridObject = 'x';
            return "Mario placed on grid.";
            break;
        }
        case 'w':
        {
            mM_currentLevel++;
            return "Mario took a warp pipe.";
            break;
        }
        case 'B':
        {
            int rando = rand() % 100;
            // if he loses:
            if (rando > 50 ) 
            {
                if (mM_powerLevel == 0 || mM_powerLevel == 1) 
                {
                    mM_numLives--;
                    mM_powerLevel = 0;
                }
                else 
                {
                    mM_powerLevel -= 2;
                }
                setBoss(false);
                return "Mario fought a boss and lost.";
            }
            // if he beats the boss:
            else 
            {
                if (mM_currentLevel == mM_levels) { // if currentlevel==mmlevels, game over you win.
                    setBoss(true);
                    mM_finalBossDefeated = true;
                    return "Mario defeated the final boss! You win!";
                    
                }
                else
                {
                    mM_currentLevel++;
                    setBoss(true);
                    return "Mario fought a boss and won.";
                }
            }
        }
    }
    coinsToLife();
    enemiesToLife();
}

void Mario::coinsToLife() { // trades in coins for a life
    if (mM_numCoins == 20) {
        mM_numCoins = 0;
        mM_numLives++;
        fileOutput("Mario traded in 20 coins for an extra life!\n");
    }
}

void Mario::enemiesToLife() { // checks if mario has earned a life by defeating enemies
    if (mM_enemiesDefeated % 7 == 0) {
        mM_numLives++;
        fileOutput("Mario defeated " + std::to_string(mM_enemiesDefeated) + " enemies and gained a life!\n");
    }
}

void Mario::fileOutput(string input) { // outputs to output.txt
    ofstream outputFile;
    outputFile.open(fileName, std::ios_base::app);
    outputFile << input;
}