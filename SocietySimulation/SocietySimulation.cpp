// SocietySimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include "Person.h"
using std::cout;

int main()
{
	// ( MVP ) Minimum Viable Product 
	
	// 1. Create one Person 
	// 2. Create one Environment 
	//		- Construct the enviorment specific decision tree
	// 3. Begin process that lets Person execute decisions
	//		- Check each threashold for all decisions
	// 4. Add all decisions to Person's life decision tree
	//		- update Person's mood based on decisions 



	Schedule p1Schedule = Schedule();
	p1Schedule.addTask("MWF 2:00pm Math Class");
	p1Schedule.addTask("T 3:00pm History Class");
	p1Schedule.addTask("TR 4:01pm Science Class");


	Person person1 = Person("Courtney");
	person1.setSchedule(&p1Schedule);
	string p1String = person1.toString();

	cout << p1String << "\n";
	cout << "Schedule: \n" << p1Schedule.toString() << "\n";

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
