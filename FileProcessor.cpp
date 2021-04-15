/* Jack Donnelly
2342203
CPSC 350-02
Assignment 5
*/
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

FileProcessor::FileProcessor() {};
FileProcessor::~FileProcessor() {};

bool FileProcessor::canOpen(string fileName) {//checks if file exists/can open
    ifstream iFS;
    iFS.open(fileName);
    if (iFS.is_open()) {
        return true;
    }
    else {
        return false;
    }
    iFS.close();
}

int FileProcessor::getLines(string fileName) {//get number of lines in file
    ifstream File;
    File.open(fileName);
    int count = 0;
    string line;
    if (File.is_open()) {
        while (!File.eof()) {
            getline(File,line);
            count++;
        }
    }
    File.close();
    return count;
}

void FileProcessor::storeInQueue(string fileName, Queue<int>* queue) {//generate queue from file
    string stringValue;
    ifstream File;
    File.open(fileName);
    while (!File.eof()) {
        getline(File, stringValue, '\n');
        //cout << stringValue << endl;
        if (isdigit(stringValue[0])) {
            queue->enqueue(stoi(stringValue));
        }
    }
    File.close();
}