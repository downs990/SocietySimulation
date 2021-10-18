#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

class Schedule
{

public: 
	Schedule();
	void addTask(string newTask);
	void removeTask(int indexToRemove);
	void updateTask();
	string toString();

private:
	// TODO: Create a Task subclass. 
	// TODO: Task properties: RepeatDays, Time, Location, Name 
	vector<string> taskList;
};

