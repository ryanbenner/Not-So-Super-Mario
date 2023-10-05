/*
1. Identifying Info:
    a. Ryan Benner
    b. 2394381
    c. rbenner@chapman.edu
    d. CPSC 350-01
    e. Assignment 1

    This class is meant to take the input file as arguments and the output file appends the game output
*/

#include "FileProcessor.h"
#include "ItemAllocation.h"

FileProcessor::FileProcessor() {
}

FileProcessor::~FileProcessor() {
}

void FileProcessor::processFile(string input, string output) {
    ifstream inputFile(input);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file" << endl;
        return;
    }

    ofstream outputFile(output);
    if (!outputFile.is_open()) {
        cerr << "Error opening the file" << endl;
        return;
    }
    
    string currentLine;
    int x = 0;
    while (!inputFile.eof()) {
        getline(inputFile, currentLine);
        arr[x] = stoi(currentLine); // converts current line from string to int (input.txt)
        x++;
    }

    inputFile.close();
    outputFile.close();
}