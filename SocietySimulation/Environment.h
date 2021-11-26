#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::cout;
using std::string;
using std::vector;
using std::map;
#include "Person.h" 

class Environment
{

public:
	Environment();
	Environment(string name);
	string getName();
	int getPopulationSize();
	void addPerson(Person *newPerson);
	void removePerson(Person *removingPerson);
	void addCondition(void(*function)(Environment, Person*));
	void addDecision(void(*function)(Environment, Person*));
	void applyConditions();
	void evaluateDecisions();

private:
	string name;
	vector<Person*> population; 

	// Vector of function pointers.
	vector<void (*)(Environment, Person*)> conditionsList;
	vector<void (*)(Environment, Person*)> decisionsList;
 

};

