#include "AdaptationEngine.h"


AdaptationEngine::AdaptationEngine(DataLogger* dataLogger, DataAnalyzer* dataAnalyzer, EnvironmentManager* envManager) {
	
	currentDataLogger = dataLogger;
	currentDataAnalyzer = dataAnalyzer;
	currentEnvManager = envManager;
}


 
void AdaptationEngine::adapt(Json::Value worldConfigJSON, time_t currentDateTime) {

	// TOOO: Turn all of these strings/keys into enums ??? 
	int worldStateIndex = worldConfigJSON["CurrentWorldState"].asInt();
	Json::Value currentSocietalInterruption = worldConfigJSON["SocietalInterruptions"][worldStateIndex];

	string societalInterruptiontype = currentSocietalInterruption["Type"].asString();
	Json::Value societalInterruptionConditions = currentSocietalInterruption["Conditions"];


	if (societalInterruptiontype == "RECESSION") {
		adaptToRecession(societalInterruptionConditions, currentDateTime);
	}
	else if (societalInterruptiontype == "PANDEMIC") {
		adaptToPandemic(societalInterruptionConditions, currentDateTime);
	}
	else if (societalInterruptiontype == "CIVIL_WAR") {
		adaptToWar(societalInterruptionConditions, currentDateTime);
	}

	 
}



// TODO: Each decision will have a positive/negative marker cooresponding to the associated S.I. ???
void AdaptationEngine::adaptToRecession(Json::Value societalInterruptionConditions, time_t currentDateTime) {
	
	float unemploymentRate = societalInterruptionConditions["UnemploymentRate"].asFloat();
	float marketPerformanceDecline = societalInterruptionConditions["StockMarketPerformanceDecline"].asFloat();

	vector<double> decisionResults = {}; 
	map<string, void (*)(Environment&, time_t )> allWorkDecisions = currentEnvManager->getAllDecisions("WORK");
	
	// TODO: Find cleaner simpler way to get .keys() and .values() of map<>
	vector<string> decisionMapKeys = {};
	vector<void (*)(Environment&, time_t )> decisionMapValues = {};
	map<string, void (*)(Environment&, time_t )>::iterator it;



	for (it = allWorkDecisions.begin(); it != allWorkDecisions.end(); it++) {
		decisionMapKeys.push_back(it->first);
		decisionMapValues.push_back(it->second);
	}


	// Apply each available decision() to each "work" environment and check outcomes. 
	for (void(*workDecision)(Environment&, time_t ) : decisionMapValues) {
				
		currentEnvManager->clearAllDecisions("WORK");
		currentEnvManager->addDecision("WORK", workDecision); 
		currentEnvManager->executeBehaviors(currentDateTime);

		// Tell data analyzer to calculate current average "QuarterlyProfitDollars" 
		double result = currentDataAnalyzer->averageEnvSpecificProperty( 
			"WORK",
			"QuarterlyProfitDollars");
		decisionResults.push_back(result);
	} 
	 
	double indexOfMaxValue = maxValueIndex(decisionResults);  
	string functionName = decisionMapKeys[indexOfMaxValue]; 
	currentDataLogger->log("RECESSION: AdaptationFound: " + functionName + "\n");
	  
}




void AdaptationEngine::adaptToPandemic(Json::Value societalInterruptionConditions, time_t currentDateTime) {}
void AdaptationEngine::adaptToWar(Json::Value societalInterruptionConditions, time_t currentDateTime) {}




// TODO: Returns all Adaptations string JSONs for each S.I that was set during the 
//    most resent run. 
vector<string> AdaptationEngine::getAllAdaptations() {
	return {};
}