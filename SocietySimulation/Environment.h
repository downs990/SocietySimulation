#pragma once

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;
#include "Person.h"

class Environment
{

public:
	Environment();
	Environment(string name);
	int getPopulationSize();
	void addPerson(Person newPerson);
	void removePerson(Person removingPerson);


private:
	string name;
	vector<Person> population;
	// Each Condition has a list of threshold criteria for it to be met. 
	// Each Condition also has a list of effects that will be applied to the 
	// person who's state meets the threshold values. 
	
	//HashMap<Condition, Thresholds[]>				(contains environment specific variables)
	//HashMap<Condition, Mood_Effects[]>
	 
	// condition: "HighProductivity"{
	//		
	//		threhsolds: {
	//				sleep >= 5, 
	//				ate_breakfast = true, 
	//				social_interactions_today <= 4    (environment specific variable)
	//			},	
	//	 
	//		mood effects: {
	//				happy+1% , 
	//				stree-1%
	//			}
	// }





	// TODO: Social interactions will require decision trees. Thresholds for their choices 
	//		will be mood.





};

