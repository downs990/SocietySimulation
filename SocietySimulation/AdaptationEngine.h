#pragma once

#include "EnvironmentManager.h"

class AdaptationEngine
{

public:

	AdaptationEngine(EnvironmentManager currentEnvManager);
	string adaptToSocietalInterruption();
	vector<string> getAllAdaptations();

	// NOTE: string is returned with the JSON dictionary containing the
	//  person values for variables to counter the specified S.I 

};

