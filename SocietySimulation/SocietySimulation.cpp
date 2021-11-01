// SocietySimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
  
#include <Windows.h>
#include "Person.h"
#include "Environment.h"
using std::cout; 




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
void highProductivity(Environment env, Person *person) {
	if (env.getName() == "Work") {
		if (
			person->getHoursSlept() >= 5  &&
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







// ( MVP ) Minimum Viable Product 
int main()
{


	// TOOD: 
	// HistoricEvent he1 = HistoricEvent(<ALL_THRESHOLDS>);
	// HistoricEvent he2 = HistoricEvent(<ALL_THRESHOLDS>);
	//                 ...


	Person person1 = Person("Courtney");
	person1.addTaskToSchedule("S", "9:00a", "5:00p", "Work");
	person1.addTaskToSchedule("S", "5:40p", "7:40p", "School");
	person1.addTaskToSchedule("S", "8:00p", "EOD", "Home");


	string p1String = person1.toString();
	cout << "Schedule: \n" << person1.getSchedule() << "\n";
	 
	cout << "Person1 Before: " << person1.toString() << "\n";

	Environment env1 = Environment("Work");
	env1.addPerson(&person1);
	env1.addCondition(highProductivity);  
	 

	// Vector of all environements 
	vector<Environment> country = { env1 };
	 


 

	 

	int const SECONDS_IN_HOUR = 3600;
	time_t now = time(0);

	while (true) { 

		struct tm newtime; 
		now += SECONDS_IN_HOUR;
		localtime_s(&newtime, &now);

		// Simulation clock: 1 second = 1 hour 
		int month = 1 + newtime.tm_mon;
		int day = newtime.tm_mday;
		int year = 1900 + newtime.tm_year;
		cout << "Date: " << month << ", " << day << " " << year << "\n";
		cout << "Time: " << newtime.tm_hour << ":" << newtime.tm_min << ":" << newtime.tm_sec << "\n";
	 	


		// 1. .applyConditions() for each env in country. (updates population state/mood)
		for (Environment currentEnv : country) {
			currentEnv.applyConditions();
		}

		cout << "Person1 After: " << person1.toString() << "\n\n\n";




		// 2. Update sim clock by 1 minutes (because shedules are minute specific)
		// 3. Check each Person in each env population for Schedule next task. (change location or social interaction)


		// 4. Loop through country to check all Person's state (salary, literacy, etc.) 
		//		for Historic Event threshold properties. 
		// 5. Use those values to check for and keep track of any Historic Event's that occur.  
		
		Sleep(1000); 
	}


	 

	 
	  
 



	cout << "\n\n\n";
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
