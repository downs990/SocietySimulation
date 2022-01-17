#include "Person.h"




Person::Person(int id, struct tm currentDateTime) {
	this->id = id;
	this->dailySchedule = Schedule();
	this->happy = 0.99;			  // To show opposite of happy, just --happy
	this->focus = 0.99;
	this->lastSlept = currentDateTime;    
	this->lastAte = currentDateTime;      

	// TODO: Every hour update sleepy and hungry by some percentage (2-5%) 
	//		 and let those ratios affect focus % 

	this->isEmployed = true;

}

double Person::getFocus(struct tm currentDateTime) {
	int MANY_HOURS_NO_SLEEP = 15;
	int MANY_HOURS_NO_EAT = 5;   

	// a = Hours since slept 
	// b = Hours since ate
	// c = Focus 

	if (this->getHoursSinceSlept(currentDateTime) >= MANY_HOURS_NO_SLEEP 	&&
		this->getHoursSinceAte(currentDateTime) >= MANY_HOURS_NO_EAT) {

		this->focus = 0.15; // Very low focus 
	}
	else if (this->getHoursSinceSlept(currentDateTime) >= MANY_HOURS_NO_SLEEP 	^
		this->getHoursSinceAte(currentDateTime) >= MANY_HOURS_NO_EAT) {
		
		// ^ is Exclusive OR 
		// If Either a is many or b is many but if both are many then don't execute this condition 
		this->focus = 0.50;
	}
	else {
		// TODO: Set to random value between 80 - 99
		this->focus = 85;
	}
	return this->focus;
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

void Person::markTaskAsComplete(string taskName) {}


Schedule Person::getSchedule() {
	return this->dailySchedule;
}
 

void Person::setHappyOffset(int offset) {
	this->happy += offset;
}
 
void Person::setLastSlept(struct tm lastSlept) { this->lastSlept; }
int Person::getHoursSinceSlept(struct tm currentDateTime) { return 0; }
int Person::getHoursSlept(struct tm currentDateTime) { return 0; }

 
void Person::setLastAte(struct tm lastAte) { this->lastAte; }
int Person::getHoursSinceAte(struct tm currentDateTime) { return 0; }
int Person::getHoursSpentEating(struct tm currentDateTime) { return 0; }


string Person::toString() {
	 
	ostringstream os;
	os << "\nId: " << this->id <<
		"  isEmployed: " << this->isEmployed <<
		"  Happy: " << this->happy;
	//	"  HoursSinceSlept: " << this->lastSlept <<
	//	"  HoursSinceAte: " << this->lastAte;
 
	// TODO: How to convert struct to string ?
	return os.str();
}

