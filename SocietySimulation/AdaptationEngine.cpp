#include "AdaptationEngine.h"


AdaptationEngine::AdaptationEngine(EnvironmentManager currentEnvManager) {
	// TODO: Use the vector<Environment>& allEnvironments; in EnvironmentManager to access entire population of people.
}


 
void AdaptationEngine::adapt(Json::Value worldConfigJSON, vector<Environment> world) {

	// TOOO: Turn all of these strings/keys into enums ??? 
	int worldStateIndex = worldConfigJSON["CurrentWorldState"].asInt();
	Json::Value currentSocietalInterruption = worldConfigJSON["SocietalInterruptions"];
	
	string societalInterruptiontype = currentSocietalInterruption["Type"].asString();
	Json::Value societalInterruptionConditions = currentSocietalInterruption["Conditions"];


	if (societalInterruptiontype == "RECESSION") {
		adaptToRecession(societalInterruptionConditions);
	}
	else if (societalInterruptiontype == "PANDEMIC") {
		adaptToPandemic(societalInterruptionConditions);
	}
	else if (societalInterruptiontype == "CIVIL_WAR") {
		adaptToWar(societalInterruptionConditions);
	}

	 
}



// TODO: Each decision will have a positive/negative marker cooresponding to the associated S.I. ???
void AdaptationEngine::adaptToRecession(Json::Value societalInterruptionConditions) {



}




void AdaptationEngine::adaptToPandemic(Json::Value societalInterruptionConditions) {}
void AdaptationEngine::adaptToWar(Json::Value societalInterruptionConditions) {}




// TODO: Returns all Adaptations string JSONs for each S.I that was set during the 
//    most resent run. 
vector<string> AdaptationEngine::getAllAdaptations() {
	return {};
}