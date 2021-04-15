/* Jack Donnelly
2342203
CPSC 350-02
Assignment 5
*/
#include <iostream>
#include <algorithm>
#include "FileProcessor.h"
#include "Student.h"
#include "Window.h"

using namespace std;

int main(int argc, char* argv[]){
	string fileName = argv[1];
	Queue<int> *gameQueue = new Queue<int>;//queue to run the game off of
	Queue<Student*> *studentQueue = new Queue<Student*>;//queue of students to be created
	FileProcessor fp;
	int insertNum = 0;//number that the student is taken out of the queue and placed into a window

	fp.storeInQueue(fileName, gameQueue);//fill gameQueue with game data

	Student* student;

	int numWindows = gameQueue->dequeue();//get number of windows open for simulation

	Window windows[numWindows];//create array of windows


	while (!gameQueue->isEmpty()) {//collect all game data and create students with specified criteria
		int arrivalTime = gameQueue->dequeue();//remove clock tick from input
		int nextNumStudents = gameQueue->dequeue();//get next number of students to be created
		for (int i = 0; i < nextNumStudents; i++) {
			insertNum++;
			if(!gameQueue->isEmpty()){
				int tNeed = gameQueue->dequeue();
				student = new Student(insertNum, tNeed, arrivalTime);//create new student with specified data
				studentQueue->enqueue(student);
			}
		}
	}
	int numStudents = studentQueue->getSize();//get total number of students for simulation
	int waitTimes[numStudents];//create array to hold student wait times
	int exitNum = 0;//used to store student times in appropriate array index
	int clockTick = 0;//game clock
	bool isRunning = true;
	while (isRunning) {
		if (clockTick >= 1) {//if its not the first loop update all of the student's wait times
			for (int i = 0; i < studentQueue->getSize(); i++) {
				Student* student = studentQueue->dequeue();
				if (student->arrivalTime < clockTick) {//only update wait times if students have already arrived
					student->incrementWaitTime();
					studentQueue->enqueue(student);
				}
				else {
					studentQueue->enqueue(student);
				}
			}
		}
		for (int i = 0; i < numWindows ;i++) {//check each window to see if its open
			if (!studentQueue->isEmpty()) {
				Student* student = studentQueue->peek();
				if (windows[i].getTimeTillIdle() == 0) {//if the window no longer is helping a student
					if (student->arrivalTime <= clockTick) {
						windows[i].handleStudent(student);//pass student to window
						int waitTime = student->getWaitTime();
						waitTimes[exitNum] = waitTime;
						studentQueue->dequeue();//student is taken care of
						exitNum++;
					}
				}
				else {
					continue;
				}
			}
			else {//finish looping if no students left
				isRunning = false;
				break;
			}
		}//window loop

		clockTick++;
		for (int i = 0; i < numWindows; i++) {//updates window idle times
			if (windows[i].getTimeTillIdle() != 0) {
				isRunning = true;//keep looping if windows are still helping students
				windows[i].decrementTimeTillIdle();
			}
			else {
				windows[i].setIdle(true);
				windows[i].incrementIdleTime();
			}
		}
	}
	int idleTimes[numWindows];
	for (int i = 0; i < numWindows; i++) {//get all idle times and store them in array
		idleTimes[i] = windows[i].getIdleTime();
	}


	sort(idleTimes, idleTimes + numWindows);//sort from lowest to highest
	sort(waitTimes, waitTimes + numStudents);
	
	float totalWait = 0;
	int numOverTen = 0;
	for (int i = 0; i < numStudents; i++) {//get t0tal for mean and count wait times > 10
		totalWait += waitTimes[i];
		if (waitTimes[i] > 10) {
			numOverTen++;
		}
	}
	float meanWait = (totalWait / numStudents);
	int medianWait = waitTimes[numStudents/2];
	int longestWait = waitTimes[numStudents - 1];

	float totalIdle = 0;
	int idleOverFive = 0;
	for (int i = 0; i < numWindows; i++) {//get total for mean and count wait times > 5
		totalIdle += idleTimes[i];
		if (idleTimes[i] > 5) {
			idleOverFive++;
		}
	}
	
	float meanIdle = float(totalIdle / numWindows);
	int longestIdle = idleTimes[numWindows-1];

	cout << "Mean student wait time: " << meanWait << endl;
	cout << "Median student wait time: " << medianWait << endl;
	cout << "Longest student wait time: " << longestWait << endl;
	cout << "Number of students waiting over 10 minutes: " << numOverTen << endl;
	cout << "Mean window idle time: " << meanIdle << endl;
	cout << "Longest window idle time: " << longestIdle << endl;
	cout << "Number of windows idle for over 5 minutes: " << idleOverFive << endl;


	delete studentQueue;
	delete gameQueue;
	

return 0;
};