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
	 
	string toString();

private:
	int id;
	Schedule dailySchedule;
	bool isEmployed;
	  
	double happy; // %              
	double focus; // %   Determines school/work performance. Is based on hoursSinceSlept, hoursSinceAte. 
	
	// NOTE: These are date-time objects just like what's used in main.
	//		Date-time objects allow you to easily calculate both "Hours since slept" and how many hours you've slept. 
	struct tm lastSlept;     
	struct tm lastAte; 
	 



};

