#include "Person.h"

Person::Person(string name ) {
	this->name = name;
	this->dailySchedule = Schedule();
	this->happy = 100; 
	this->stress = 0;        
	this->hoursSlept = 8;     
	this->ateBreakfast = true;  
}


void Person::addTaskToSchedule(string newTask) {
	this->dailySchedule.addTask(newTask);
}

// TODO: Add subclass in Schedule for a task class.    | Task has: completed, name, time, etc..
void Person::markTaskAsComplete(string taskName) {}


string Person::getSchedule() { 
	return this->dailySchedule.toString();
}

void Person::setHappyOffset(int offset) {
	this->happy += offset;
}

void Person::setStressOffset(int offset) { this->stress += offset; }
void Person::setHoursSleptOffset(int offset) { this->hoursSlept += offset; }
int Person::getHoursSlept() { return this->hoursSlept; }
bool Person::getAteBreakfast() { return this->ateBreakfast; }

string Person::toString() {
	return "Name: " + this->name +
		"\nHappy: " + std::to_string(this->happy) + 
		"\nStress: " + std::to_string(this->stress);
}

