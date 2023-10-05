/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1
*/

#include "Game.h"
#include "FileProcessor.h"
#include "ItemAllocation.h"
#include <iostream>
using namespace std;

int main (int argc, char** argv) {


    FileProcessor* fp = new FileProcessor();
    fp->processFile(argv[1], argv[2]);
    ItemAllocation* ia = new ItemAllocation(fp->getArr(3), fp->getArr(4), fp->getArr(5), fp->getArr(6), fp->getArr(7), fp->getArr(1));
    ia->convertToNum();
    Game* game = new Game(ia->getCoins(), ia->getMushrooms(), ia->getNothing(), ia->getGoombas(), ia->getKoopas(), fp->getArr(0), fp->getArr(1), fp->getArr(2), argv[2]);
    game->runGame(); // NEED TO GET OUTPUT OF RUNGAME() TO APPEAR IN OUTPUT.TXT
    delete fp;
    delete game;
    delete ia;
}
