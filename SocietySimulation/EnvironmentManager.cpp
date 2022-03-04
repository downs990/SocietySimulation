#include "EnvironmentManager.h"




void schoolDecisionTree1(Environment& env, struct tm currentDateTime) { // Chagne * to & 



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
		//	if (person->getHoursSinceSlept() > 15) {              // SLEEP

		//		// Sleep 2 hours 
		//		//person->setHoursSinceSlept(0);
		//	}
		//	else if (person->getAteBreakfast() == false) {	// EAT
		//	   // Traverse EAT subtree 


		//	}
		//	else if (true) {                               // STUDY


		//	   // TODO: Check their schedule to see when their exams are for each class

		//	   // - Update schedule gernation class to be able to 
		//	   //   add random quizes and a couple of exams at the correct 
		//	   //   intervals for each class that this person is in. 
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

// schoolDecisionTree2()  // Take Notes 
// schoolDecisionTree3()  // Ask Questions 


void workDecisionTree1(Environment& env, struct tm currentDateTime) {
}
void homeDecisionTree1(Environment& env, struct tm currentDateTime) {
}





void recessionCondition(Environment& env, Json::Value relatedConditions) {


	// Unemploy the percentage of population to match unemploymentRate.
	double unemploymentRate = relatedConditions["UnemploymentRate"].asDouble();
	int numberOfUnemployed = (*env.getPopulation()).size() * unemploymentRate;

	for (int i = 0; i < numberOfUnemployed; i++) {

		Person& currentPerson = (*env.getPopulation())[i];
		currentPerson.setEmployment(false);
	}

}

void pandemicCondition(Environment& env, Json::Value relatedConditions) {
	
	double rateOfInfection = relatedConditions["percentageOfPopulationInfected"].asDouble();
	int numberOfInfected = (*env.getPopulation()).size() * rateOfInfection;
	for (int i = 0; i < numberOfInfected; i++) {
		Person& currentPerson = (*env.getPopulation())[i];
		currentPerson.setHealthState(StateOfHealth::PANDEMIC_VIRUS);
	}
}




// Precondition: Unemployed
// Postcondition: Employed, Homeless (Unemployed)
void unemployedDecisionTree(Environment& env, time_t currentDateTime) {
	// 1. Go back to school to change fields
	// 2. Start new business online
	// 3. Find another job with lower or same salary.
	// 4. End up homeless 

	// NOTE: Decision is based on skills and education level.

}

// Precondition: Infected 
// Postcondition: Healthy again, Dead 
void infectedWithVirusDecisionTree(Environment& env, struct tm currentDateTime) {
	// 1. Social distance and mask up
	// 2. Get vaccinated 
	// 3. Alternative treatments 

	// NOTE: Decision is based on education level and underlining health conditions.
}


void warDecisionTree(Environment& env, struct tm currentDateTime) {
	// 1. 

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

// TODO: Why these parameters ? 
void EnvironmentManager::executeBehaviors(struct tm newSimClockStruct, time_t newSimClockTValue) {
	simClockStruct = newSimClockStruct;
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


		// TODO: Just testing simClock and getFocus() 
		currentEnv.addDecision(unemployedDecisionTree);





		// TODO: Test all environmental decisions. 
		//if (currentEnv.getType() == "SCHOOL") {
		//	currentEnv.addDecision(schoolDecisionTree1);
		//}
		//else if (currentEnv.getType() == "WORK") {
		//	currentEnv.addDecision(workDecisionTree1);
		//}
		//else if (currentEnv.getType() == "HOME") {
		//	currentEnv.addDecision(homeDecisionTree1);
		//}
		 

	}


}


