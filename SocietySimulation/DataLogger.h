#pragma once 

#include <string>
using std::string;


class DataLogger
{

public: 

	DataLogger();
	string createNewSessionLog();  // return session log file
	void saveSessionData(string dataToSave);

private: 

	string currentSessionLogFile;


};

