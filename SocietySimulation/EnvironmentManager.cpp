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

vector<void (*)(Environment&, time_t currentDateTime)> EnvironmentManager::getAllWorkDecisions() {

	vector<void (*)(Environment&, time_t currentDateTime)> workDecisions;
	workDecisions.push_back(workDecisionTree1);
	workDecisions.push_back(workDecisionTree2);
	workDecisions.push_back(workDecisionTree3);

	return workDecisions;

}

void schoolDecisionTree(Environment& env, time_t currentDateTime) { // Chagne * to & 


	// TODO: Loop through env.getPopulation() to apply to every person in env. 
	Person* person = &(*env.getPopulation())[0];

	string taskName = "Time between classes";
	int timeBetweenClasses = 0;
	string prevClassTime = "12:00pm";

	// 1. Evaluate schedule of person in env. 
	for (Schedule::SimTask currentTask : person->getSchedule().getTasks()) {
		string currClassTime = currentTask.getStartTime();

		//// TODO: Properly compare times  
		//if ((currClassTime < prevClassTime) >= 3) {
		//	if (person->getHoursSinceSlept() > 15) {           // SLEEP

		//		// Sleep 2 hours 
		//		//person->setHoursSinceSlept(0);
		//	}
		//	else if (person->getAteBreakfast() == false) {	   // EAT
		//		// Traverse EAT subtree 
		//	}
		//	else if (true) {								   // STUDY
		//	}
		//}
	}


	// 2. If time between classes is 3h >= then present the following decisions:  
	//			EAT                SLEEP              STUDY 
	//         /                                        \
	//  @ school    @ resturant                        subjectA   subjectB
	//                    \                        (Exam tomorrow)  (Exam next week)    
	//         placeA   placeB  placeC
	//          /           |      \
	//     2miles        1.5miles    4miles
	//(happy+=1,hungry=0)  (happy+=2,hungry=10%)  (happy+=4,hungry=5%) 


	// TODO: Evaluate each decision against thresholds and adjust Person's state/mood based on choice. 
	// TODO: Evaulate if/else nest v. Real Decision Trees
	//		https://stats.stackexchange.com/questions/398322/what-is-the-purpose-of-using-a-decision-tree


} 


void homeDecisionTree(Environment& env, time_t currentDateTime) {
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


 

// Removes all decisions functions from "decisionsList" for each Env of type "envType"
void EnvironmentManager::clearAllDecisions(string envType) {

}

// Adds the specified decision function to all Environments of type "envType"
void EnvironmentManager::addDecision(string envType, void (*)(Environment&, time_t currentDateTime)) {


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
		else if (currentEnv.getType() == "HOME") {
			currentEnv.addDecision(homeDecisionTree);

			// Add Environment Specific Variables (What's needed for measuring H.E or S.I ?)
			// ...
		}
		else if (currentEnv.getType() == "SCHOOL") {
			currentEnv.addDecision(schoolDecisionTree);


			// Add Environment Specific Variables (What's needed for measuring H.E or S.I ?)
			// ...
		}
		 

	}


}


