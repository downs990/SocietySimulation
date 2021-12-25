#include "Environment.h"


Environment::Environment() {

} 
 
Environment::Environment(int i, string t) : id(i) , type(t) { 
	population = {};
}

string Environment::getType() { return type; }

vector<Person*> Environment::getPopulation() {
	return population;
}

void Environment::addPerson(Person *newPerson) {
	population.push_back(newPerson);
}

void Environment::removePerson(Person *removingPerson) { }

 
void Environment::addCondition(EnvironmentalCondition newCondition) {
	conditionsList.push_back(newCondition);
}

vector<EnvironmentalCondition> Environment::getConditionsList() {
	return conditionsList;
}

void Environment::addDecision(void (*function)(Environment*, Person*)) {
	decisionsList.push_back(function);
}

vector<void (*)(Environment*, Person*)> Environment::getDecisionsList(){
	return decisionsList;
}
 

string Environment::toString() {

	string output = "\nId: " + std::to_string(id) 
		+ " Type: " + type 
		+ " PopulationSize: " + std::to_string(population.size() );
	return output;
}