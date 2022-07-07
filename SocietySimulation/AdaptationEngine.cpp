#include "AdaptationEngine.h"


AdaptationEngine::AdaptationEngine(DataLogger dataLogger, DataAnalyzer dataAnalyzer, EnvironmentManager envManager) {
	
	currentDataLogger = dataLogger;
	currentDataAnalyzer = dataAnalyzer;
	currentEnvManager = &envManager;
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
	vector<void (*)(Environment&, time_t)> allWorkDecisions = currentEnvManager->getAllWorkDecisions();
	 
	// Apply each available decision() to each "work" environment and check outcomes. 
	for (void(*workDecision)(Environment&, time_t) : allWorkDecisions) {
				
		currentEnvManager->clearAllDecisions("WORK");
		currentEnvManager->addDecision("WORK", workDecision);

		// 1. Execute attached decisions 
		// TODO: Causes ERROR !
		// currentEnvManager->executeBehaviors(currentDateTime);

		// 2. Tell data analyzer to calculate current average "QuarterlyProfitDollars" 
		// (i.e StockMarketPerfrmance) for each Business (i.e. Work)
		//currentDataAnalyzer.calculate("Average", "QuarterlyProfitDollars");

		// 3. DecisionResults.append(results)
	}

	int maxValueIndex = 0;  // TODO: decisionResults.getIndexOfMaxValue();
	void(*bestDecisionToCounterRecession)(Environment&, time_t) = allWorkDecisions[maxValueIndex];

	string functionName = "";// TODO: bestDecisionToCounterRecession.Name;

	// Log found results 
	currentDataLogger.log("RECESSION: AdaptationFound: " + functionName);
	  

}




void AdaptationEngine::adaptToPandemic(Json::Value societalInterruptionConditions, time_t currentDateTime) {}
void AdaptationEngine::adaptToWar(Json::Value societalInterruptionConditions, time_t currentDateTime) {}




// TODO: Returns all Adaptations string JSONs for each S.I that was set during the 
//    most resent run. 
vector<string> AdaptationEngine::getAllAdaptations() {
	return {};
}