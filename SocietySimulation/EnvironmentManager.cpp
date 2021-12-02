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

	string taskName = "Time between classes";
	int timeBetweenClasses = 0;
	string prevClassTime = "12:00pm";

	// 1. Evaluate schedule of person in env. 
	for (Schedule::SimTask currentTask : person->getSchedule().getTasks()) {
		string currClassTime = currentTask.getStartTime();

		// TODO: Properly compare times  
		if ((currClassTime < prevClassTime) >= 3) {
			if (person->getHoursSlept() < 5) {              // SLEEP

				// Sleep 2 hours 
				person->setHoursSleptOffset(2);  

			}else if (person->getAteBreakfast() == false) {	// EAT
				// Traverse EAT subtree 

			}else if (true) {                               // STUDY

				// TODO: How to know if they have exam tomorrow??? 
			}

		}
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



}

// schoolDecisionTree2()  // Take Notes 
// schoolDecisionTree3()  // Ask Questions 


void workDecisionTree1(Environment env, Person* person) {
}
void homeDecisionTree1(Environment env, Person* person) {
}

