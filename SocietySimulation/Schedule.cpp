#include "Schedule.h"


 



Schedule::SimTask::SimTask(string repeatDays, string startTime, string endTime, string locationName)
{
	// TODO: Make start and end time DateTime objects. 
	this->repeatDays = repeatDays;
	this->startTime = startTime;
	this->endTime = endTime;
	this->locationName = locationName;
}
string Schedule::SimTask::getRepeatDays() {
	return this->repeatDays;
}
string Schedule::SimTask::getStartTime(){
	return this->startTime;
}
string Schedule::SimTask::getEndTime() {
	return this->endTime;
}
string Schedule::SimTask::getlocationName() {
	return this->locationName;
}





Schedule::Schedule() {
	taskList = {};
}


void Schedule::addTask(string repeatDays, string startTime, string endTime, string locationName) {
	
	SimTask newTask = SimTask(repeatDays, startTime, endTime, locationName);
	taskList.push_back(newTask);
}

void Schedule::removeTask(int indexToRemove) {
}

void Schedule::updateTask() {
}

string Schedule::toString() {

	string output = "";
	for (SimTask task : taskList) {
		output += " { " + 
						task.getRepeatDays() + " " + task.getStartTime() + " " +
						task.getEndTime() + " " + task.getlocationName() + 
				  " } \n";
	}

	return output;
}



 