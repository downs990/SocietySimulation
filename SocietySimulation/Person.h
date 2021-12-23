#pragma once

#include "Schedule.h"
#include "MyConstants.h"
#include <string>
using std::string;


class Person
{
public:
	Person(int id);
	void addTaskToSchedule(string repeatDays, string startTime, string endTime, string locationName);
	void markTaskAsComplete(string taskName);
	
	Schedule getSchedule(); 

	void setHappyOffset(int offset);
	void setStressOffset(int offset);
	void setHoursSleptOffset(int offset); // +1 every hour slept 
	int getHoursSlept();
	bool getAteBreakfast();
	string toString();

private:
	int id;
	Schedule dailySchedule;
	
	// TODO: Social interactions will require decision trees. Thresholds for their choices 
	//		will be mood.


	// moods / health state
	int happy;         // % 0 - 100 
	int stress;        // % 0 - 100
	int hoursSlept;    // 0 - 15
	bool ateBreakfast; // true , false



};

