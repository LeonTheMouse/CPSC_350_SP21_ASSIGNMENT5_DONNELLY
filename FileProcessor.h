/* Jack Donnelly
2342203
CPSC 350-02
Assignment 5
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include "Queue.h"

#include <iostream>

using namespace std;

class FileProcessor{
public:
	FileProcessor();
	~FileProcessor();

	bool canOpen(string inputFile);//checks if file can open
	int getLines(string inputFile);
	void storeInQueue(string fileName, Queue<int>* queue);
};

#endif