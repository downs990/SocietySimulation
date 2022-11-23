#pragma once

#include "Schedule.h"
#include "MyConstants.h"
#include "DataLogger.h"
#include <string>
#include <sstream>

#include <fstream>
#include <iostream> 
using std::ofstream;
using std::ifstream;
using std::string; 
using std::ostringstream;


class Person
{
public:

	Person(int id);
	void addTaskToSchedule(string repeatDays, string startTime, string endTime, string locationName);
	void markTaskAsComplete(string taskName);
	
	Schedule getSchedule(); 

	void setHealthState(StateOfHealth healthState);
	StateOfHealth getHealthState();
	 
	double getHappy(time_t currentDateTime);
	double getFocus(time_t currentDateTime); // NOTE: No setFocus() needed.
	void setEmployment(bool employmentStatus);
	bool getEmployment();
	void setHappyOffset(int offset); 
	 
	void setLastSlept(time_t lastSlept);
	time_t getLastSlept ();
	void setLastAte(time_t lastAte);
	time_t getLastAte();

	// TODO: Add function for updating dsspg
	
	// TODO: Can I get away with not having this variable???
	//int getHoursSpentEating(time_t currentDateTime); 
	 
	int getKnowledgeScore();
	void setKnowledgeScoreOffset(int offset);
	
	
	 
	
	string toString();




private:
	int id;
	Schedule dailySchedule;
	StateOfHealth healthState;
	bool isEmployed;
	// TODO: Create a simple scaled numbering system that can be incremented when they study/learn new things.
	//		This variable can be considered when they are looking for new employment. 
	
	
	
	// Total study hours
	int knowledgeScore;




	// Used to calculate happy % 
	double disciplined; // %
	int dsspg;          // Days since made significant process on person goals
	  
	// Used to calculate focus %  
	time_t lastSlept;
	time_t lastAte; 
	// ^
	// NOTE: These are date-time objects just like what's used in main.
	//		Date-time objects allow you to easily calculate both "Hours since slept" and how many hours you've slept. 


	//double happy; // %              
	//double focus; // %   Determines school/work performance. Is based on hoursSinceSlept, hoursSinceAte. 

	// ^
	// NOTE: Don't need explicit variables for these. They are 
	//		calculated/derived only and exactly when needed using
	//		implicit variables below. 



};

