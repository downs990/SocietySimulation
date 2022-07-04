#pragma once

#include "EnvironmentManager.h"
#include <string>

using std::string;

class AdaptationEngine
{

private:
	
	void adaptToRecession(Json::Value societalInterruptionConditions);
	void adaptToPandemic(Json::Value societalInterruptionConditions);
	void adaptToWar(Json::Value societalInterruptionConditions);


public:

	AdaptationEngine(EnvironmentManager currentEnvManager);
	void adapt(Json::Value worldConfigJSON, vector<Environment> world);
	vector<string> getAllAdaptations();

	// NOTE: string is returned with the JSON dictionary containing the
	//  person values for variables to counter the specified S.I 

};

