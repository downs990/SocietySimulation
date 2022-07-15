#pragma once 

#include <string> 
#include <iostream>
#include <fstream>

using namespace std;
using std::string;


static string createNewSessionLog() {
	// 1. Create file name (Session ID ++ from last session .txt) 
	// 2. Create file 
	// 3. Return file name direct path 
	return "";
}


// TODO: Should I move this to "MyConstants.h" or turn DataLogger back into a 
//		.cpp and .h class ??? 
static void logSimData(string dataToSave) {

	ofstream myfile;
	myfile.open("SessionDataLogs.txt", ios_base::app);// ios_base::app means append to file instead of overwrite. 
	myfile << dataToSave;
	myfile.close();


}