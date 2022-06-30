#include "DataLogger.h"
#include <iostream>
#include <fstream>

using namespace std;

DataLogger::DataLogger() {
	this->currentSessionLogFile = createNewSessionLog();

}


string DataLogger::createNewSessionLog() {
	// 1. Create file name (Session ID ++ from last session .txt) 
	// 2. Create file 
	// 3. Return file name direct path 
	return "";
}

void DataLogger::saveSessionData(string dataToSave) {
	 
	ofstream myfile;
	myfile.open("SessionDataLogs.txt", ios_base::app);// ios_base::app means append to file instead of overwrite. 
	myfile << dataToSave;
	myfile.close();


}