#include "Person.h"

Person::Person(string name ) {
	this->name = name;
	this->dailySchedule = Schedule();
}


void Person::addTaskToSchedule(string newTask) {
	this->dailySchedule.addTask(newTask);
}

void Person::markTaskAsComplete(string taskName) {
	// TODO: Add subclass in Schedule for a task class. 
	//		Task has: completed, name, time, etc..
}


string Person::getSchedule() { 
	return this->dailySchedule.toString();
}

string Person::toString() {
	return "Name: " + this->name;
}

