#pragma once

#include "EnvironmentManager.h"
#include "DataLogger.h"
#include "DataAnalyzer.h"

#include <string>   

using std::string; 

class AdaptationEngine
{

 
public:

	AdaptationEngine(DataLogger* dataLogger, DataAnalyzer* dataAnalyzer, EnvironmentManager* currentEnvManager);
	void adapt(Json::Value worldConfigJSON, time_t currentDateTime);
	vector<string> getAllAdaptations();

	// NOTE: string is returned with the JSON dictionary containing the
	//  person values for variables to counter the specified S.I 

private:

	DataLogger* currentDataLogger;
	DataAnalyzer* currentDataAnalyzer;
	EnvironmentManager* currentEnvManager;

	void adaptToRecession(Json::Value societalInterruptionConditions, time_t currentDateTime);
	void adaptToPandemic(Json::Value societalInterruptionConditions, time_t currentDateTime);
	void adaptToWar(Json::Value societalInterruptionConditions, time_t currentDateTime);

	
};

