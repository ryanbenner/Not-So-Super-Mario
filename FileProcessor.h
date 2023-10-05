/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is meant to take the input file as arguments and the output file appends the game output
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Game.h"
#include <fstream>
#include <string>

class FileProcessor {
    public:
        FileProcessor(); // constructor
        virtual ~FileProcessor(); // destructor

        void processFile(string input, string output); // processes file
        int getArr(int pos) { return arr[pos]; }; // returns the array of arguments from input.txt

    private:
        Game* mFP_Game; // game
        int arr[8]; // stores arguments from input.txt
};

#endif