#pragma once

#include "Schedule.h"
#include <string>
using std::string;


class Person
{
public:
	Person(string name);
	void setSchedule(Schedule *dailySchedule);
	string toString();

private:
	string name;
	Schedule *dailySchedule;


};

