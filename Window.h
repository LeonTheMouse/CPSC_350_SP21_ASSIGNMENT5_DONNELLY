/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/
#ifndef WINDOW_H
#define WINDOW_H
#include "Student.h"

class Window{
public:
	Window();
	~Window();

	int idleTime;//total idle time for simulation 
	void incrementIdleTime();
	void decrementTimeTillIdle();
	int getIdleTime();
	int timeTillIdle;//uses timeneeded from student to stay idle for specified time
	int getTimeTillIdle();
	void setIdle(bool idle);
	void handleStudent(Student* student);//processes student data and updates window appropriately
	void toggleIdle();
	bool getIdle();
	bool isIdle;

	
};

#endif