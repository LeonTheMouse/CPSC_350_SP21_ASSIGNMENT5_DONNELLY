/* Jack Donnelly
2342203
CPSC 350-02
Assignment 4
*/

#include "Window.h"
#include <iostream>

Window::Window() {
	idleTime = 0;
	isIdle = false;
	timeTillIdle = 0;
}

Window::~Window() {}

void Window::incrementIdleTime() {
	idleTime++;
}

void Window::decrementTimeTillIdle() {
	timeTillIdle--;
}


int Window::getIdleTime() {
	return idleTime;
}

int Window::getTimeTillIdle() {
	return timeTillIdle;
}

void Window::toggleIdle() {
	if (isIdle) {
		isIdle = false;
	}
	else {
		isIdle = true;
	}
}

bool Window::getIdle() {
	return isIdle;
}

void Window::setIdle(bool idle) {
	isIdle = isIdle;
}

void Window::handleStudent(Student* student) {
	isIdle = false;
	timeTillIdle = student->timeNeeded;
}