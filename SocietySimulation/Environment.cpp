#include "Environment.h"

 
Environment::Environment(int i, string t) : id(i) , type(t) { 
	population = {};
}





void Environment::setPopulation(vector<Person> newPopulation) {
	population = newPopulation;
}

string Environment::getType() { return type; }


vector<Person>* Environment::getPopulation() {
	return &population;
}

void Environment::addPerson(Person newPerson) {
	population.push_back(newPerson);
}

void Environment::removePerson(Person removingPerson) { }
 

void Environment::addDecision(void(*function)(Environment&, time_t currrentDateTime))
{
	decisionsList.push_back(function);
}
 
 

vector<void (*)(Environment&, time_t currentDateTime)> Environment::getDecisionsList(){
	return decisionsList;
}
 

string Environment::toString() {

	string output = "\nId: " + std::to_string(id) 
		+ " Type: " + type 
		+ " PopulationSize: " + std::to_string(population.size() );
	return output;
}