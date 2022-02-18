#include "DataAnalyzer.h" 

DataAnalyzer::DataAnalyzer(vector<Environment> world) {
}


// TODO: Read all events from EventLogs.json and store it in currentEventsLogs variable
Json::Value DataAnalyzer::getEventLogs() {
	return currentEventLogs;
}


// TODO: Loop through world and check stats of each person and evnironment and update
//     EventLogs.json data accordingly. 
void DataAnalyzer::updateEventLogs() {

}

// TODO: Check if values in EventLogs.json match the thresholds in WorldConfig.json for 
//     any expected HistoricEvents. 
void DataAnalyzer::compareCurrentDataToEventThresholds() {

}

