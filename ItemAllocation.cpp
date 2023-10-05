/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is solely meant to convert the item percentages to the correct number of items to fill the grid
*/

#include "ItemAllocation.h"

ItemAllocation::ItemAllocation() {
    mIA_mushrooms = 0;
    mIA_coins = 0;
    mIA_goombas = 0;
    mIA_koopas = 0;
    mIA_nothing = 0;
}

ItemAllocation::ItemAllocation(int pKoopas, int pNothing, int pGoombas, int pCoins, int pMushrooms, int gridSize) {
    mIA_pKoopas = pKoopas;
    mIA_pNothing = pNothing;
    mIA_pGoombas = pGoombas;
    mIA_pCoins = pCoins;
    mIA_pMushrooms = pMushrooms;
    mIA_gridSize = gridSize;
    mIA_koopas = 0;
    mIA_nothing = 0;
    mIA_goombas = 0;
    mIA_coins = 0;
    mIA_mushrooms = 0;
    srand(static_cast<int>(time(0)));
}

ItemAllocation::~ItemAllocation(){
}

void ItemAllocation::convertToNum() { // converts percentages of items to number of items
    int randy;
    while (mIA_numItems < mIA_gridSize*mIA_gridSize) {
        randy = rand() % 100;
        if (randy < mIA_pKoopas) {
            mIA_koopas++;
            mIA_numItems++;
        }
        else if (randy >= mIA_pKoopas && randy < mIA_pKoopas+mIA_pNothing) {
            mIA_nothing++;
            mIA_numItems++;
        }
        else if (randy >= mIA_pKoopas+mIA_pNothing && randy < mIA_pKoopas+mIA_pNothing+mIA_pGoombas) {
            mIA_goombas++;
            mIA_numItems++;
        }
        else if (randy >= mIA_pKoopas+mIA_pNothing+mIA_pGoombas && randy < mIA_pKoopas+mIA_pNothing+mIA_pGoombas+mIA_pMushrooms) {
            mIA_mushrooms++;
            mIA_numItems++;
        }
        else if (randy >= mIA_pKoopas+mIA_pNothing+mIA_pGoombas+mIA_pMushrooms && randy < mIA_pKoopas+mIA_pNothing+mIA_pGoombas+mIA_pMushrooms+mIA_pCoins) {
            mIA_coins++;
            mIA_numItems++;
        }
    }
}

