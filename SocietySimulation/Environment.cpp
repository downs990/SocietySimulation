#include "Environment.h"


Environment::Environment() {

}

Environment::Environment(string n) : name(n) {}

int Environment::getPopulationSize() {
	return population.size();
}

void Environment::addPerson(Person newPerson) {
	population.push_back(newPerson);
}

void Environment::removePerson(Person removingPerson) {
	// TODO: remove person.
}