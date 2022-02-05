#pragma once

#include "Schedule.h"
#include "MyConstants.h"
#include <string>
#include <sstream>
using std::string; 
using std::ostringstream;


class Person
{
public:
	Person(int id, struct tm currentDateTime);
	void addTaskToSchedule(string repeatDays, string startTime, string endTime, string locationName);
	void markTaskAsComplete(string taskName);
	
	Schedule getSchedule(); 

	void setHealthState(StateOfHealth healthState);
	StateOfHealth getHealthState();
	 
	double getHappy(struct tm currentDateTime);
	double getFocus(struct tm currentDateTime); // NOTE: No setFocus() needed.
	void setEmployment(bool employmentStatus);
	bool getEmployment();
	void setHappyOffset(int offset); 
	
	// TODO: How to use strcut as arg? 
	//Or use string instead and convert string to struct inside. 
	void setLastSlept(struct tm lastSlept); 

	// TODO: Calculate using lastSlept DateTime object
	//and current time.
	int getHoursSinceSlept(struct tm currentDateTime); 
	int getHoursSlept(struct tm currentDateTime);
	
	void setLastAte(struct tm lastAte);

	// TODO: Calculate using lastSlept DateTime 
	//object and current time.
	int getHoursSinceAte(struct tm currentDateTime);
	int getHoursSpentEating(struct tm currentDateTime);
	//static double calculateHoursDifference(struct tm dateA, struct tm dateB);
	string toString();


private:
	int id;
	Schedule dailySchedule;
	StateOfHealth healthState;
	bool isEmployed;
	 
	// Used to calculate happy % 
	double disciplined; // %
	int dsspg;          // Days since made significant process on person goals
	  
	// Used to calculate focus %  
	struct tm lastSlept;     
	struct tm lastAte; 
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

