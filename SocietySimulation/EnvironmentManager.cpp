#include "EnvironmentManager.h"
#include <map>



// TODO: Only execute work decisions @ 12 Noon)
void workDecisionTree1(Environment& env, time_t currentDateTime) {
	// Eat Lunch 
	
	vector<Person>* population = env.getPopulation();
	for (Person &p : *population) {
		if (p.getHappy(currentDateTime) < 0.80) {
			 
			time_t hoursSinceAte = p.getLastAte() - currentDateTime; // TODO: Calculate this correctly.
			if(hoursSinceAte >= 5 ){
				// Eat 
				p.setLastAte(currentDateTime);
				p.setHappyOffset(10);
			}
		}
	}
}

 

// TODO: Only execute work decisions @ 12 Noon)
void workDecisionTree2(Environment& env, time_t currentDateTime) {
	// Socialize 

	vector<Person>* population = env.getPopulation();
	for (Person& p : *population) {

		int max = 100, max1 = 1;
		int min = 1, min1 = 0;

		int range = max - min + 1;
		int range1 = max1 - min1 + 1;

		int compatibilityScore = rand() % range + min;
		int sign = rand() % range1 + min1; // + or -

		double currentHappy = p.getHappy(currentDateTime);

		if (sign == 0) {
			// Negative 
			p.setHappyOffset( -(compatibilityScore*10) );
		}
		else {
			// Positive 
			p.setHappyOffset( compatibilityScore * 10 );
		}
	}
}

// TODO: Only execute work decisions @ 12 Noon)
void workDecisionTree3(Environment& env, time_t currentDateTime) {
	// Work 

	vector<Person>* population = env.getPopulation();
	for (Person& p : *population) {
		if (p.getHappy(currentDateTime) > 0.90) {

			time_t hoursSinceAte = p.getLastAte() - currentDateTime; // TODO: Calculate this correctly.
			if (hoursSinceAte < 5) {
				// Perform more work 
				p.setHappyOffset(5);

				// Increment business profits by 2% 
				Json::Value environmentSpecificVars = env.getEnvironmentSpecificVars();
				float currentProfits = environmentSpecificVars["QuarterlyProfitDollars"].asFloat();

				environmentSpecificVars["QuarterlyProfitDollars"] = currentProfits + (currentProfits * 0.02);
				env.setEnvironmentSpecificVars(environmentSpecificVars);
			}
		}
	}

}

 

void schoolDecisionTree1(Environment& env, time_t currentDateTime) {} 
void schoolDecisionTree2(Environment& env, time_t currentDateTime) {}


// TODO: Only execute during time between classes. (in schedule)
void schoolDecisionTree3(Environment& env, time_t currentDateTime) {
	// Study / Homework

	vector<Person>* population = env.getPopulation();
	for (Person& p : *population) {
		
		for (Schedule::SimTask currentTask : p.getSchedule().getTasks()) {
			// 1. Keep track of previous class time. 
			// 2. Keep track of current class time.
			// 3. Time between those classes is when this decision will execute. 
		}

		time_t hoursSinceAte = p.getLastAte() - currentDateTime;     // TODO: Calculate this correctly.
		time_t hoursSinceSlept = p.getLastSlept() - currentDateTime; // TODO: Calculate this correctly.

		if (hoursSinceAte < 5) {
			if (hoursSinceSlept < 8) {
			 
				p.setKnowledgeScoreOffset(1); // knowledge++ 
			 
			}
		}
	}
}

void schoolDecisionTree4(Environment& env, time_t currentDateTime) {}

void homeDecisionTree1(Environment& env, time_t currentDateTime) {}
void homeDecisionTree2(Environment& env, time_t currentDateTime) {}
void homeDecisionTree3(Environment& env, time_t currentDateTime) {}


// TODO: Evaulate if/else decision nest v. Real Decision Trees
//		https://stats.stackexchange.com/questions/398322/what-is-the-purpose-of-using-a-decision-tree


map<string, void (*)(Environment&, time_t)> EnvironmentManager::getAllDecisions(string envType) {

	map<string, void (*)(Environment&, time_t)> envDecisions;

	if (envType == "WORK") { 
		envDecisions["workDecisionTree1"] = workDecisionTree1;
		envDecisions["workDecisionTree2"] = workDecisionTree2;
		envDecisions["workDecisionTree3"] = workDecisionTree3;
	}
	else if (envType == "SCHOOL") { 
		envDecisions["schoolDecisionTree1"] = schoolDecisionTree1;
		envDecisions["schoolDecisionTree2"] = schoolDecisionTree2;
		envDecisions["schoolDecisionTree3"] = schoolDecisionTree3;
		envDecisions["schoolDecisionTree4"] = schoolDecisionTree4;
	}
	else if (envType == "HOME") { 
		envDecisions["homeDecisionTree1"] = homeDecisionTree1;
		envDecisions["homeDecisionTree2"] = homeDecisionTree2;
		envDecisions["homeDecisionTree3"] = homeDecisionTree3;
	}
	 
	return envDecisions;

}



void recessionCondition(Environment& env, Json::Value relatedConditions) {


	// Unemploy the percentage of population to match unemploymentRate.
	double unemploymentRate = relatedConditions["UnemploymentRate"].asDouble();
	int numberOfUnemployed = (*env.getPopulation()).size() * unemploymentRate;

	for (int i = 0; i < numberOfUnemployed; i++) {

		Person& currentPerson = (*env.getPopulation())[i];
		currentPerson.setEmployment(false);
	}

	// Implement this by setting each Business Enviornment's performance returns to decline by 22%
	double marketPerformanceDecline = relatedConditions["StockMarketPerformanceDecline"].asDouble();

	  
	if (env.getType() == "WORK") {
		Json::Value envSpecificVars = env.getEnvironmentSpecificVars();
		
		// Calculate new value 
		float currentProfit = envSpecificVars["QuarterlyProfitDollars"].asFloat();
		float newProfit = currentProfit - (currentProfit * marketPerformanceDecline);
		
		// update existing value
		envSpecificVars["QuarterlyProfitDollars"] = newProfit;
		env.setEnvironmentSpecificVars(envSpecificVars);
	}


}


void pandemicCondition(Environment& env, Json::Value relatedConditions) {
	
	double rateOfInfection = relatedConditions["PopulationInfected"].asDouble();
	int numberOfInfected = (*env.getPopulation()).size() * rateOfInfection;
	for (int i = 0; i < numberOfInfected; i++) {
		Person& currentPerson = (*env.getPopulation())[i];
		currentPerson.setHealthState(StateOfHealth::PANDEMIC_VIRUS);
	}
}


void EnvironmentManager::clearAllDecisions(string envType) {

	for (Environment& env : allEnvironments) {
		if (env.getType() == envType) {
			// Removes all decisions from "decisionsList" for each Env of type "envType"
			env.clearDecisions();
		}
	}
}

 
void EnvironmentManager::addDecision(string envType, void (*newDecision)(Environment&, time_t)) {

	for (Environment& env : allEnvironments) {
		if (env.getType() == envType) {
			// Adds the specified decision function to all Environments of type "envType"
			env.addDecision(newDecision);
		}
	}

}




void EnvironmentManager::applyConditions() {
	for (Environment& currentEnv : allEnvironments) {

		int currentWorldState = worldConfigJSON["CurrentWorldState"].asInt();
		Json::Value currentSIConditions = worldConfigJSON["SocietalInterruptions"][currentWorldState]["Conditions"];

		if (currentWorldState == 0) {
			// Normal 
		}
		else if (currentWorldState == 1) {
			// Recession 
			recessionCondition(currentEnv, currentSIConditions);
		}
		else if (currentWorldState == 2) {
			// Pandemic 
			pandemicCondition(currentEnv, currentSIConditions);
		}
		else if (currentWorldState == 3) {
			// Civil War
		}


		// TODO: Remove currentEnv.getConditionsList()
		// TODO: Remove conditionsList from Environment.cpp and .h
		// TODO: Should you have Environmental Conditions be different for Home, work, school and sub environments? 

	}

}




void EnvironmentManager::evaluateDecisions() {

	 
	for (Environment& currentEnv : allEnvironments) { 

		for (auto&& func : currentEnv.getDecisionsList()) {
			func(currentEnv, simClockTValue);
		}

	}
}

void EnvironmentManager::executeScheduleTasks() {

}
 

void EnvironmentManager::executeBehaviors(time_t newSimClockTValue) { 
	simClockTValue = newSimClockTValue;

	// The time period for each environment type that is for making decisions in the design doc.
	// Environmental Decisions section Decision Flow. 
	bool decisionPeriod = true;
	if (decisionPeriod) {
		evaluateDecisions();
	}
	else {
		executeScheduleTasks();
	}
	 
	

}


EnvironmentManager::EnvironmentManager(vector<Environment>& myEnvironments,
	Json::Value  worldConfig) : allEnvironments(myEnvironments), worldConfigJSON(worldConfig) {



	for (Environment& currentEnv : allEnvironments) {

		  

	
		Json::Value environmentSpecificVars = {};



		// TODO: Add and test all environment specific decisions. 
		if (currentEnv.getType() == "WORK") {
			currentEnv.addDecision(workDecisionTree1);

			environmentSpecificVars["QuarterlyProfitDollars"] = 100000.00;
			currentEnv.setEnvironmentSpecificVars(environmentSpecificVars);
			// ...



		}
		else if (currentEnv.getType() == "SCHOOL") {
			//currentEnv.addDecision(schoolDecisionTree1);
			//currentEnv.addDecision(schoolDecisionTree2);
			currentEnv.addDecision(schoolDecisionTree3);      // Tests "FirstWorldCountry" H.E
			//currentEnv.addDecision(schoolDecisionTree4);

			// Add Environment Specific Variables (What's needed for measuring H.E or S.I ?)
			// ...
		}
		else if (currentEnv.getType() == "HOME") {
			currentEnv.addDecision(homeDecisionTree1);


			// Add Environment Specific Variables (What's needed for measuring H.E or S.I ?)
			// ...
		}
		 

	}


}


