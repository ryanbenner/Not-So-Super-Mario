/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is solely meant to convert the item percentages to the correct number of items to fill the grid
*/

#ifndef ITEMALLOCATION_H
#define ITEMALLOCATION_H
#include "FileProcessor.h"

class ItemAllocation {
    public:
        ItemAllocation(); // constructor
        ItemAllocation(int pKoopas, int pNothing, int pGoombas, int pCoins, int pMushrooms, int gridSize); // oload constructor
        ~ItemAllocation(); // destructor

        int getNothing() { return mIA_nothing; }; // gets number of x
        int getKoopas() { return mIA_koopas; }; // gets number of k
        int getGoombas() { return mIA_goombas; }; // gets number of g
        int getCoins() { return mIA_coins; }; // gets number of c
        int getMushrooms() { return mIA_mushrooms; }; // gets number of m

        void convertToNum(); // converts percentages to numbers of items
    private:
        // percentages of each item, allocated through 'input.txt'
        int mIA_pKoopas;
        int mIA_pNothing; 
        int mIA_pGoombas;
        int mIA_pCoins; 
        int mIA_pMushrooms;

        // numbers of each item, to provide to Game()
        int mIA_koopas;
        int mIA_nothing;
        int mIA_goombas;
        int mIA_coins;
        int mIA_mushrooms;

        // counter for current number of items allocated, and the grid size
        int mIA_numItems;
        int mIA_gridSize;
};

#endif