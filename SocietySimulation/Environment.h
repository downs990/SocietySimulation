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
	Environment(int id, string type);

	void setPopulation(vector<Person> newPopulation);
	string getType();
	vector<Person>* getPopulation(); 
	void addPerson(Person newPerson);
	void removePerson(Person removingPerson); 
	void addCondition(EnvironmentalCondition newCondition);
	vector<EnvironmentalCondition> getConditionsList();
	void addDecision(void(*function)(Environment*));
	vector<void (*)(Environment*)> getDecisionsList();
	string toString();

private:
	int id;
	string type;    // ex, Work
	string subType; // ex, Hospital 
	vector<Person> population; 

	// Vector of function pointers. 
	vector<EnvironmentalCondition> conditionsList;
	vector<void (*)(Environment*)> decisionsList;
 

};

