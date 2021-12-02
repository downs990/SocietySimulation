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


	// TODO: Should this be a struct ?? 
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


	Schedule();
	void addTask(string repeatDays, string startTime, string endTime, string locationName);
	void removeTask(int indexToRemove);
	void updateTask();
	vector<SimTask> getTasks();
	string toString();

private: 
	vector<SimTask> taskList;




 
};

