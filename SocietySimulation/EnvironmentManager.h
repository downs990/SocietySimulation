#pragma once
#include "Environment.h"
 

/// Handles Decision trees of each environment and also environmental conditions. 
class EnvironmentManager
{ 

public: 

	// TODO: Based on currentEnv.name, attach the correct decision tree. 
	EnvironmentManager(vector<Environment>& allEnvironments, Json::Value  worldConfigJSON);
	
	 
	vector<void (*)(Environment&, time_t currentDateTime)> getAllWorkDecisions();
	void applyConditions();
	void evaluateDecisions(); 
	void executeBehaviors(time_t simClockTValue);
	void executeScheduleTasks();

	// Removes all decisions functions from "decisionsList" for each Env of type "envType"
	void clearAllDecisions(string envType);

	// Adds the specified decision function to all Environments of type "envType"
	void addDecision(string envType, void (*)(Environment&, time_t currentDateTime));

private: 
	vector<Environment>& allEnvironments; 
	Json::Value  worldConfigJSON; 
	time_t simClockTValue;

};

