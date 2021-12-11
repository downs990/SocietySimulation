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
	vector<Person*> getPopulation();
	void addPerson(Person *newPerson);
	void removePerson(Person *removingPerson); 
	void addCondition(EnvironmentalCondition newCondition);
	vector<EnvironmentalCondition> getConditionsList();
	void addDecision(void(*function)(Environment*, Person*));
	vector<void (*)(Environment*, Person*)> getDecisionsList();

private:
	string name;
	vector<Person*> population; 

	// Vector of function pointers. 
	vector<EnvironmentalCondition> conditionsList;
	vector<void (*)(Environment*, Person*)> decisionsList;
 

};

