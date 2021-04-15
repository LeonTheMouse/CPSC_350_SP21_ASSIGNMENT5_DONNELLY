/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#include "Student.h"
#include <iostream>

Student::Student(){
	waitTime = 0;
	insertNum = 0;
	timeNeeded = 0;
	arrivalTime = 0;
	Waiting = false;
}

Student::Student(int inNum, int tNeed, int arrTime) {
	timeNeeded = tNeed;
	insertNum = inNum;
	arrivalTime = arrTime;
	waitTime = 0;
	Waiting = true;
}

Student::~Student() {}

int Student::getWaitTime() {
	return waitTime;
}

bool Student::isWaiting() {
	if (Waiting) {
		return true;
	}
	else {
		return false;
	}
}

void Student::incrementWaitTime() {
	waitTime++;
}

void Student::setWaiting(bool x) {
	Waiting = x;
}
//operator overload to compare students
bool Student::operator==(Student x) {
	if (insertNum == x.insertNum) {
		return true;
	}
	else {
		return false;
	}
}

bool Student::operator!=(Student x) {
	if (insertNum == x.insertNum) {
		return false;
	}
	else {
		return false;
	}
}



