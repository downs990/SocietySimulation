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
void highProductivity(Environment& env) {
	 
	Person& person = (*env.getPopulation())[0];

	//if (env->getType() == "WORK") {
		if (
			person.getHoursSlept() >= 5 &&
			person.getAteBreakfast() == true
			)
		{ 
			person.setHappyOffset(1);   // happy += 1
			person.setStressOffset(-1); // stress -= 1
		}
	//}
}

// Environmental Condition 2
// Environmental Condition 3 
//            ... 





 
void schoolDecisionTree1(Environment* env) { // Chagne * to & 
	 


	// TODO: Loop through env.getPopulation() to apply to every person in env. 
	Person* person = &(*env->getPopulation())[0];


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
	// TODO: Evaulate if/else nest v. Real Decision Trees
	//		https://stats.stackexchange.com/questions/398322/what-is-the-purpose-of-using-a-decision-tree


}

// schoolDecisionTree2()  // Take Notes 
// schoolDecisionTree3()  // Ask Questions 


void workDecisionTree1(Environment* env) {
}
void homeDecisionTree1(Environment* env) {
}

void EnvironmentManager::applyConditions() {
	for (Environment& currentEnv : allEnvironments) {

		// Add all environmental conditions first. 
		for (int i = 0; i < currentEnv.getConditionsList().size(); i++)
		{
			EnvironmentalCondition currentCondition = currentEnv.getConditionsList()[i];
			if (currentCondition == EnvironmentalCondition::HIGH_PRODUCTIVITY) {
				  
				 

				//cout << "\n\n\nFirst Person Before: " << firstPerson.toString();
				highProductivity(currentEnv);
				//cout << "\n\n\nFirst Person After: " << firstPerson.toString();
			}
		}
	}

}


// TODO: Some Environmental conditions should only be applied once. 



void unemployedCondition(Environment* env) {
	// TODO: Pull conditions from WorldConfig.json
}

void pandemicCondition(Environment* env) {
	// TODO: Pull conditions from WorldConfig.json
}




// Precondition: Unemployed
// Postcondition: Employed, Homeless (Unemployed)
void unemployedDecisionTree(Environment* env) {
	// 1. Go back to school to change fields
	// 2. Start new business online
	// 3. Find another job with lower or same salary.
	// 4. End up homeless 

	// NOTE: Decision is based on skills and education level.
}

// Precondition: Infected 
// Postcondition: Healthy again, Dead 
void infectedWithVirusDecisionTree(Environment* env) {
	// 1. Social distance and mask up
	// 2. Get vaccinated 
	// 3. Alternative treatments 

	// NOTE: Decision is based on education level and underlining health conditions.
}


void warDecisionTree(Environment* env) {
	// 1. 

}






void EnvironmentManager::evaluateDecisions() {

	for (Environment& currentEnv : allEnvironments) {
		for (auto&& func : currentEnv.getDecisionsList()) {
			func(&currentEnv ); // TODO: Apply to each person in evn
		}
	
	}
}

 
EnvironmentManager::EnvironmentManager(vector<Environment>& myEnvironments): allEnvironments(myEnvironments){
	   
 
	for (Environment currentEnv : allEnvironments) {


		// Add all environmental decisions. 
		if (currentEnv.getType() == "SCHOOL") {
			currentEnv.addDecision(schoolDecisionTree1);
		}
		else if (currentEnv.getType() == "WORK") {
			currentEnv.addDecision(workDecisionTree1);
		}
		else if (currentEnv.getType() == "HOME") {
			currentEnv.addDecision(homeDecisionTree1);
		}

	}


}
  

