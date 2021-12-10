#include "EnvironmentManager.h"


// Environmental Condition 1
// condition: "HighProductivity"{
//		
//		threhsolds: {
//				sleep >= 5, 
//				ate_breakfast = true, 
//				social_interactions_today <= 4    (environment specific variable)
//			},	
//	 
//		mood effects: {
//				happy+1% , 
//				stree-1%
//			}
// }
void highProductivity(Environment *env, Person *person) {
	if (env->getName() == "Work") {
		if (
			person->getHoursSlept() >= 5 &&
			person->getAteBreakfast() == true
			)
		{
			person->setHappyOffset(1);   // happy += 1
			person->setStressOffset(-1); // stress -= 1
		}
	}
}

// Environmental Condition 2
// Environmental Condition 3
// Environmental Condition 4
//            ...

// TODO: Move all Environmental Conditions to their own function files. 
//		- WorkConditions.cpp
//	    - SchoolConditions.cpp
//		- HomeConditions.cpp










// TODO: How to execute this for every person in env??? 
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
			}
			else if (person->getAteBreakfast() == false) {	// EAT
			   // Traverse EAT subtree 
				
			}
			else if (true) {                               // STUDY


			   // TODO: Check their schedule to see when their exams are for each class
			   
			   // - Update schedule gernation class to be able to 
			   //   add random quizes and a couple of exams at the correct 
			   //   intervals for each class that this person is in. 
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

EnvironmentManager::EnvironmentManager(vector<Environment*> myEnvironments){

	allEnvironments = myEnvironments;
	for (Environment *currentEnv : allEnvironments) {


		// Add all environmental conditions first. 
		for (int i = 0; i < currentEnv->getConditionsList().size(); i++)
		{
			string currentCondition = currentEnv->getConditionsList()[i];
			if (currentCondition == "HIGH_PRODUCTIVITY") {

				Person *firstPerson = currentEnv->getPopulation()[0];
				highProductivity( currentEnv, firstPerson );
			}
		}



		// Then add all environmental decisions. 
		if (currentEnv->getName() == "school") {
			currentEnv->addDecision(schoolDecisionTree1);
		}
		else if (currentEnv->getName() == "work") {
			currentEnv->addDecision(workDecisionTree1);
		}
		else if (currentEnv->getName() == "home") {
			currentEnv->addDecision(homeDecisionTree1);
		}

	}


}
  

