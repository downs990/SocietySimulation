#include "Schedule.h"


 
Schedule::Schedule() {
	taskList = {};
}


void Schedule::addTask(string newTask) {
	taskList.push_back(newTask);
}

void Schedule::removeTask(int indexToRemove) {
}

void Schedule::updateTask() {
}

string Schedule::toString() {

	string output = "";
	for (string task : taskList) {
		output += task + "\n";
	}

	return output;
}