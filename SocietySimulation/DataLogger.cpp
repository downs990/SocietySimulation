#include "DataLogger.h"


DataLogger::DataLogger() {
	this->currentSessionLogFile = createNewSessionLog();

}


string DataLogger::createNewSessionLog() {
	// 1. Create file name (Session ID ++ from last session .txt) 
	// 2. Create file 
	// 3. Return file name direct path 
}

void DataLogger::saveSessionData(string dataToSave) {

	// 1. Open file 
	// 2. Write data 
	// 3. Close file 


}