#include "EnvironmentManager.h"


EnvironmentManager::EnvironmentManager(vector<Environment> myEnvironments){

	allEnvironments = myEnvironments;

	for (Environment currentEnv : allEnvironments) {

		if (currentEnv.getName() == "school") {
			currentEnv.addDecision(schoolDecisionTree1);
		}
		else if (currentEnv.getName() == "work") {
			currentEnv.addDecision(workDecisionTree1);
		}
		else if (currentEnv.getName() == "home") {
			currentEnv.addDecision(homeDecisionTree1);
		}

	}


}
  
void schoolDecisionTree1(Environment env, Person* person) {

	// 1. Evaluate schedule of person in env. 
	// 2. If time between classes is 3h >= then present the following decisions:  
	//			EAT                SLEEP              STUDY 
	//         /                                        \
	//  @ school    @ resturant                        subjectA   subjectB
	//                    \
	//         placeA   placeB  placeC
	// 
}

// schoolDecisionTree2()  // Take Notes 
// schoolDecisionTree3()  // Ask Questions 


void workDecisionTree1(Environment env, Person* person) {
}
void homeDecisionTree1(Environment env, Person* person) {
}

