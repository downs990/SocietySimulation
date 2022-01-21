#include "Person.h"




Person::Person(int id, struct tm currentDateTime) {
	this->id = id;
	this->dailySchedule = Schedule();
	this->healthState = StateOfHealth::HEALTHY;

	// TODO: Init dsspg and disciplined 
	this->lastSlept = currentDateTime;    
	this->lastAte = currentDateTime;      
	 

	this->isEmployed = true;

}


void Person::setHealthState(StateOfHealth healthState) {
	this->healthState = healthState;
}

StateOfHealth Person::getHealthState() {
	return this->healthState;
}


// If dsspg reaches 10 then happy = 0 
// If dsspg > 10 then happy < 0 
double Person::getHappy(struct tm currentDateTime) {
	
	// Converts dsspg to percentage and subtracts that percentage of f from f
	double f = getFocus(currentDateTime);
 	double happy = f - ((dsspg * 0.10) * f);

	return happy;
}


// TODO: Turn into formula instead of conditionals.
double Person::getFocus(struct tm currentDateTime) {

	double focus = 0;
	int MANY_HOURS_NO_SLEEP = 15;
	int MANY_HOURS_NO_EAT = 5;   

	// a = Hours since slept 
	// b = Hours since ate
	// c = Focus 

	if (this->getHoursSinceSlept(currentDateTime) >= MANY_HOURS_NO_SLEEP 	&&
		this->getHoursSinceAte(currentDateTime) >= MANY_HOURS_NO_EAT) {

		focus = 0.15; // Very low focus 
	}
	else if (this->getHoursSinceSlept(currentDateTime) >= MANY_HOURS_NO_SLEEP 	^
		this->getHoursSinceAte(currentDateTime) >= MANY_HOURS_NO_EAT) {
		
		// ^ is Exclusive OR 
		// If Either a is many or b is many but if both are many then don't execute this condition 
		focus = 0.50;
	}
	else {
		// TODO: Set to random value between 80 - 99
		focus = 85;
	}
	return focus;
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
 
 
 
void Person::setLastSlept(struct tm lastSlept) { this->lastSlept; }
int Person::getHoursSinceSlept(struct tm currentDateTime) { return 0; }
int Person::getHoursSlept(struct tm currentDateTime) { return 0; }

 
void Person::setLastAte(struct tm lastAte) { this->lastAte; }
int Person::getHoursSinceAte(struct tm currentDateTime) { return 0; }
int Person::getHoursSpentEating(struct tm currentDateTime) { return 0; }


string Person::toString() {
	// TODO: Pass current tm currentDateTime to this function.
	 
	ostringstream os;
	os << "\nId: " << this->id <<
		"  isEmployed: " << this->isEmployed;
	//	"  Happy: " << this->getHappy() << 
	//	"  Focus: " << this->getFocus() <<
	//	"  HoursSinceSlept: " << this->lastSlept <<
	//	"  HoursSinceAte: " << this->lastAte;
 
	// TODO: How to convert struct to string ?
	return os.str();
}

