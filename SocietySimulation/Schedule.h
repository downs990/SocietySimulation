#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

class Schedule
{
	class SimTask {
	public:
		SimTask(string repeatDays, string startTime, string endTime, string locationName);
		string getRepeatDays();
		string getStartTime();
		string getEndTime();
		string getlocationName();
	private:
		string repeatDays;
		string startTime;
		string endTime;
		string locationName;
		//TODO: taskName;
	};



public: 
	Schedule();
	void addTask(string repeatDays, string startTime, string endTime, string locationName);
	void removeTask(int indexToRemove);
	void updateTask();
	string toString();

private: 
	vector<SimTask> taskList;




 
};

