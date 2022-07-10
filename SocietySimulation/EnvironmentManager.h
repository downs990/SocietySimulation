#pragma once
#include "Environment.h"
 

/// Handles Decision trees of each environment and also environmental conditions. 
class EnvironmentManager
{ 

public: 

	// TODO: Based on currentEnv.name, attach the correct decision tree. 
	EnvironmentManager(vector<Environment>& allEnvironments, Json::Value  worldConfigJSON);
	
	 
	map<string, void (*)(Environment&, time_t currentDateTime)> getAllDecisions(string envType);
	void applyConditions();
	void evaluateDecisions(); 
	void executeBehaviors(time_t simClockTValue);
	void executeScheduleTasks();

	// Removes all decisions functions from "decisionsList" for each Env of type "envType"
	void clearAllDecisions(string envType);

	// Adds the specified decision function to all Environments of type "envType"
	void addDecision(string envType, void (*newDecision)(Environment&, time_t) );

private: 
	vector<Environment>& allEnvironments; 
	Json::Value  worldConfigJSON; 
	time_t simClockTValue;


	// NOTE: Avoids me having to write accessors and mutators for "allEnvironments" 
	//	   and "worldConfigJSON". Also, I'll be able to keep those variables 
	//	   encapsulated into EnvironmentManager class;
	friend class DataAnalyzer;
};

