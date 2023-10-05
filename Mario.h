/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is to handle what happens in marios move, such as whether he wins or loses against an enemy
*/

#ifndef MARIO_H
#define MARIO_H
#include "Game.h"
#include "World.h"

class Mario {
    public:
        Mario() {}; // constructor
        Mario(int gridSize, int levels, int lives, string file); // overloaded constructor
        virtual ~Mario(); // destructor

        void setRow(int row) { mM_row = row; }; // sets mario's row position
        void setCol(int col) { mM_col = col; }; // sets mario's col position
        void setObj(char c) { mM_gridObject = c; }; // sets the object mario landed on in previous turn
        void setBoss(bool b) { mM_bossDefeated = b; }; // variable to check if he just beat a boss


        int getRow() { return mM_row; }; // get mario's row position
        int getCol() { return mM_col; }; // get mario's col position
        int getPwrLvl() { return mM_powerLevel; }; // get mario's power level
        int getLives() { return mM_numLives; }; // get mario's lives
        int getCoins() { return mM_numCoins; }; // get mario's coins
        int getBossesDefeated() { return mM_bossesDefeated; }; // get number of bosses defeated
        char getObj() { return mM_gridObject; }; // gets the object mario is 'standing on'
        bool getBoss() { return mM_bossDefeated; }; // checks if mario just beat a boss
        bool getFinalBoss() { return mM_finalBossDefeated; }; // checks if mario just beat the final boss

        void coinsToLife(); // checks if mario has collected 20 coins, gives him a life if so
        void enemiesToLife(); // checks if mario has defeated a multiple of 7, gives him a life if so

        string whatHappened(); // handles what happened in marios turn

        void fileOutput(string input); // allows text output to file

    private:
        int mM_currentLevel; // current level
        int mM_levels; // num levels
        int mM_gridSize; // grid size
        int mM_numLives; // number of lives
        int mM_numCoins; // number of coins
        int mM_powerLevel; // power level
        int mM_enemiesDefeated; // num enemies defeated
        int mM_row; // mario row pos
        int mM_col; // mario col pos
        int mM_bossesDefeated; // num bosses defeated
        char mM_gridObject; // object mario is 'standing on'
        bool mM_bossDefeated; // checks if mario defeated a boss
        bool mM_finalBossDefeated; // checks if mario defeated final boss
        string fileName; // output.txt
};

#endif