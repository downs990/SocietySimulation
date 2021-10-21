#include "Environment.h"


Environment::Environment() {

}

Environment::Environment(string n) : name(n) {
}

string Environment::getName() { return this->name; }

int Environment::getPopulationSize() {
	return population.size();
}

void Environment::addPerson(Person *newPerson) {
	population.push_back(newPerson);
}

void Environment::removePerson(Person *removingPerson) { }

void Environment::addCondition(void (*function)(Environment, Person*)) {
	conditionsList.push_back(function);
}

void Environment::applyConditions() {

	if (population.size() > 0) {

		Person* firstPerson = population[0];
		for (auto&& func : conditionsList) {
			func(*this, firstPerson);
		}
	}
	 
	 

}