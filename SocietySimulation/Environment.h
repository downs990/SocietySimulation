#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <json\value.h>
#include <json\json.h>
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
	void addDecision(void(*function)(Environment&, time_t));
	vector<void (*)(Environment&, time_t)> getDecisionsList();
	void setEnvironmentSpecificVars(Json::Value environmentSpecificVars);
	Json::Value getEnvironmentSpecificVars();
	string toString();

private:
	int id;
	string type;    // ex, Work
	string subType; // ex, Hospital 
	vector<Person> population; 

	// Vector of function pointers.  
	vector<void (*)(Environment&, time_t)> decisionsList;
 
	 
	Json::Value environmentSpecificVars = {};



};

