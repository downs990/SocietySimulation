#pragma once

#include "Schedule.h"
#include <string>
using std::string;


class Person
{
public:
	Person(string name);
	void addTaskToSchedule(string newTask);
	void markTaskAsComplete(string taskName);
	string getSchedule();
	string toString();

private:
	string name;
	Schedule dailySchedule;


};

