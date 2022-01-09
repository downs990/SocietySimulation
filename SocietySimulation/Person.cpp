#include "Person.h"






Person::Person(int id ) {
	this->id = id;
	this->dailySchedule = Schedule();
	this->happy = 100; 
	this->stress = 2;        
	this->hoursSlept = 8;     
	this->ateBreakfast = true;  
	this->isEmployed = true;

	
}
 
void Person::setEmployment(bool employmentStatus) {
	this->isEmployed = employmentStatus;
}

bool Person::getEmployment() {
	return this->isEmployed;
}

void Person::addTaskToSchedule(string repeatDays, string startTime, string endTime, string locationName) {
	this->dailySchedule.addTask(repeatDays, startTime, endTime, locationName);
}

// TODO: Add subclass in Schedule for a task class.    | Task has: completed, name, time, etc..
void Person::markTaskAsComplete(string taskName) {}

Schedule Person::getSchedule() {
	return this->dailySchedule;
}
 

void Person::setHappyOffset(int offset) {
	this->happy += offset;
}

void Person::setStressOffset(int offset) { this->stress += offset; }
void Person::setHoursSleptOffset(int offset) { this->hoursSlept += offset; }
int Person::getHoursSlept() { return this->hoursSlept; }
bool Person::getAteBreakfast() { return this->ateBreakfast; }

string Person::toString() {
	 

	ostringstream os;
	os << "\nId: " << this->id <<
		"  isEmployed: " << this->isEmployed << 
		"  Happy: " << this->happy <<
		"  Stress: " << this->stress <<
		"  HoursSlept: " << this->hoursSlept;
 
	return os.str();
}

