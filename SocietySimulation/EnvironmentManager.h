#pragma once
#include "Environment.h"


/// Handles Decision trees of each environment and also environmental conditions. 
class EnvironmentManager
{ 

public: 

	// TODO: Based on currentEnv.name, attach the correct decision tree. 
	EnvironmentManager(vector<Environment> allEnvironments);

	// School Decisions
	//void schoolDecisionTree1(Environment env, Person* person);
	// Work Decisions 
	//void workDecisionTree1(Environment env, Person* person);
	// Home Decisions
	//void homeDecisionTree1(Environment env, Person* person);

private: 
	vector<Environment> allEnvironments;


};

