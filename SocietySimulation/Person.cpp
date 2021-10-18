#include "Person.h"

Person::Person(string name ) {
	this->name = name;
}


void Person::setSchedule(Schedule *dailySchedule) {
	this->dailySchedule = dailySchedule;
}

string Person::toString() {
	return "Name: " + this->name;
}

