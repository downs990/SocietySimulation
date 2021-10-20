// SocietySimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <Windows.h>
#include "Person.h"
#include "Environment.h"
using std::cout; 

int main()
{
	// ( MVP ) Minimum Viable Product 
	 

	// 1. Create one Person 
	Person person1 = Person("Courtney");
	person1.addTaskToSchedule("MWF 2:00pm Math Class");
	person1.addTaskToSchedule("T 3:00pm History Class");
	person1.addTaskToSchedule("TR 4:01pm Science Class");


	string p1String = person1.toString();

	cout << p1String << "\n";
	cout << "Schedule: \n" << person1.getSchedule() << "\n";

	// 2. Create one Environment 
	//		- Construct the enviorment specific decision tree
	Environment env1 = Environment("Workplace 1");
	env1.addPerson(person1);

	// 3. Begin process that lets Person execute decisions
	//		- Check each threashold for all decisions
	// 4. Add all decisions to Person's life decision tree
	//		- update Person's mood based on decisions 
	// 0. Create simple sim clock



	// Main simulation loop
	while (true) { 
		Sleep(1000);
		cout << "." ;



	}

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
