/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#ifndef STUDENT_H
#define STUDENT_H
 
#include <iostream>

class Student {
public:
	Student();
	Student(int inNum, int tNeed, int arrTime);//overloaded constructor
	~Student();

	int waitTime;//counts the time student waits till they get picked up by a window
	int arrivalTime;//keeps track of when a student is meant to get picked up by a window
	int timeNeeded;//time for student at window
	int insertNum;//used to differentiate students
	bool Waiting;//true when student is waiting to be picked up by a window

	int getWaitTime();
	void incrementWaitTime();
	void setWaiting(bool x);
	bool isWaiting();
	bool operator == (Student x);
	bool operator != (Student x);

};



#endif