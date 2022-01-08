#include "Person.h"






Person::Person(int id ) {
	this->id = id;
	this->dailySchedule = Schedule();
	this->happy = 100; 
	this->stress = 2;        
	this->hoursSlept = 8;     
	this->ateBreakfast = true;  

	
}

vector<int> Person::getValues() {
	vector<int> values = {this->happy, this->stress, this->hoursSlept};
	return values;
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

	//cout << this->id << " " << this->happy << " " << this->stress << "\n";

	ostringstream os;
	os << "\nId: " << this->id <<
		"  Happy: " << this->happy <<
		"  Stress: " << this->stress <<
		"  HoursSlept: " << this->hoursSlept;
 
	return os.str();
}

