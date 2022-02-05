#pragma once
#include "Environment.h"
#include <json\value.h>
#include <json\json.h>

/// Handles Decision trees of each environment and also environmental conditions. 
class EnvironmentManager
{ 

public: 

	// TODO: Based on currentEnv.name, attach the correct decision tree. 
	EnvironmentManager(vector<Environment>& allEnvironments, Json::Value  worldConfigJSON);
	void applyConditions();
	void evaluateDecisions(); 
	void getSimClockTime(struct tm simClockStruct, time_t simClockTValue);

private: 
	vector<Environment>& allEnvironments; 
	Json::Value  worldConfigJSON;
	struct tm simClockStruct;
	time_t simClockTValue;

};

