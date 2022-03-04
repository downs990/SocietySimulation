// SocietySimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
  
#include <Windows.h> 
#include <fstream>
#include <iostream> 

#include "Person.h"
#include "Environment.h"
#include "EnvironmentManager.h"
#include "DataAnalyzer.h"
#include "AdaptationEngine.h"

using std::cout; 
using std::cin;
using std::to_string;
using std::ofstream;
using std::ifstream;

 

vector<Environment> world;
Json::Value  worldConfigJSON;

void createDatabase() {
	// TODO: Create a MongoDB 
	// TODO: Create database shcema and designs (update design docs)
	// TODO: Add logs to this db in main sim loop
}


// Populates the world variable with objects generated from 
// values in the "WorldConfiguration.json" file. 
void readWorldDataFromConfigFile() {

	Json::Reader reader;   
	Json::Value newValue;   
	Json::StyledStreamWriter writer;  
	ofstream newFile;

	//opening file using fstream
	ifstream file("C:\\Users\\downs\\Desktop\\VisualStudioWorkspace\\SocietySimulation\\SocietySimulation\\WorldConfiguration.json");

	// check if there is any error is getting data from the json file
	if (!reader.parse(file, newValue)) {
		cout << reader.getFormattedErrorMessages();
	} 
	 

	// Generate environment objects from Json World file.
	int environmentID = 0;
	worldConfigJSON = newValue;
	Json::Value environmentsToCreate = newValue["Environments"];
	for (Json::Value env : environmentsToCreate) {
		
		string type = env["Type"].asString();
		int count = env["Count"].asInt();
		int populationSize = env["PopulationSize"].asInt();
		  

		for (int i = 0; i < count; i++) {
			Environment newEnvironment = Environment(environmentID, type); 

			for (int j = 0; j < populationSize; j++) {
				
				//time_t now = time(0);
				Person newPerson = Person(i + j);//, now);
				newEnvironment.addPerson(newPerson);
			}

			world.push_back(newEnvironment);
			environmentID++;
		}
	 
	}

	// Print world for debugging
	for (Environment env : world) {
		cout << env.toString();
	}

 

}



////Updating the json data
//newValue["Category"] = "Technical";

////we can add new values as well
//newValue["first"] = "Shishank";
//newValue["last"] = "Jain";

//// make the changes in a new file/original file
//newFile.open("items.json");
//writer.write(newFile, newValue);
//newFile.close();


int main()
{
	 

	// TODO: Update WorldConfig.json to be more flexible.
	readWorldDataFromConfigFile();
	createDatabase();
 
	
	 
	 
	// Attaches all decision trees to associated environment types. 
	EnvironmentManager envManager = EnvironmentManager(world, worldConfigJSON);
	envManager.applyConditions();

	DataAnalyzer myDataAnalyzer = DataAnalyzer();

	// Steps: 
	// - Reads the current S.I from the WorldConfig.json file 
	// - Starts trying random values for each person's variables associated with how they make decisions. 
	// - Use the Data Analyzer to check if those random values are making the person make more decisions that will 
	//      counter the effects of the current S.I 
	AdaptationEngine myAdaptor = AdaptationEngine(envManager);
 



	 

	int const SECONDS_IN_HOUR = 3600;
	time_t now = time(0);
	 
	while (true) { 
		

		// TODO: Log the state of the simulation every frame to a file. 
		//     Either specific Env/Persons or entire world. 
		struct tm newtime; 
		now += SECONDS_IN_HOUR;
		localtime_s(&newtime, &now);

		// Simulation clock: 1 second = 1 hour 
		int month = 1 + newtime.tm_mon;
		int day = newtime.tm_mday;
		int year = 1900 + newtime.tm_year;
		cout << "\nDate: " << month << ", " << day << " " << year << "\n";
		cout << "Time: " << newtime.tm_hour << ":" << newtime.tm_min << ":" << newtime.tm_sec << "\n";
	 	

		
		envManager.executeBehaviors(newtime, now);

		// Checks for Historic Events. 
		vector<string> positiveAndNegativeMarkers = myDataAnalyzer.updateEventLogs(world);

		// Adapts world population. 
		myAdaptor.adaptToSocietalInterruption(positiveAndNegativeMarkers, world);


		



// **************************************************************************************
// Testing Focus Function 

		int const SECONDS_IN_HOUR = 3600;
		time_t nowA = now;//time(0);
		time_t nowB = now;//time(0);

		//a = 96    b = 168    weight = 4     Focus = 2
		//a = 48    b = 84     weight = 6     Focus = 28
		//a = 3     b = 5      weight = 60    Focus = 58
		struct tm newtimeA;
		struct tm newtimeB;
		nowA -= (SECONDS_IN_HOUR * 48); // 96 hours ago 
		nowB -= (SECONDS_IN_HOUR * 84); // 168 hours ago      // weight = 4  Focus=2


		localtime_s(&newtimeA, &nowA);
		localtime_s(&newtimeB, &nowB);


		struct tm lastSlept = newtimeA;
		struct tm lastAte = newtimeB;


		Person* p1 = &(* (&world[0])->getPopulation())[0];
		p1->setLastSlept(nowA);
		p1->setLastAte(nowB);


		int hoursSinceSlept = calculateHoursDifference(nowA, now);
		int hoursSinceAte = calculateHoursDifference(nowB, now);

		cout << "hoursSinceSlept: " << hoursSinceSlept << "\n";
		cout << "hoursSinceAte: " << hoursSinceAte << "\n";

		 

		char buffer[26];
		char buffer2[26];
		strftime(buffer, 26, "A: %Y-%m-%d %H:%M:%S", &lastSlept);
		strftime(buffer2, 26, "B: %Y-%m-%d %H:%M:%S", &lastAte);
		puts(buffer);
		puts(buffer2);
		cout << "\n";



		double focus = p1->getFocus(now);
		cout << "Focus: " << focus << "\n\n";

// *********************************************************************************



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
