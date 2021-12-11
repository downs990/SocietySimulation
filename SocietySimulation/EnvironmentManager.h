#pragma once
#include "Environment.h"


/// Handles Decision trees of each environment and also environmental conditions. 
class EnvironmentManager
{ 

public: 

	// TODO: Based on currentEnv.name, attach the correct decision tree. 
	EnvironmentManager(vector<Environment*> allEnvironments);
	void applyConditions();
	void evaluateDecisions(); 

private: 
	vector<Environment*> allEnvironments;


};

