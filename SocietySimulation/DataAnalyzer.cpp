#include "DataAnalyzer.h" 

DataAnalyzer::DataAnalyzer(vector<Environment>& currentWorld) : world(currentWorld) { 
}


// TODO: Read all events from EventLogs.json and store it in currentEventsLogs variable
Json::Value DataAnalyzer::getEventLogs() {
	return currentEventLogs;
}


// TODO: Loop through world and check each persons state/mood variables and evnironment and update
//     EventLogs.json data with the current running values for expected thresholds. 
vector<string> DataAnalyzer::updateEventLogs() {


	compareCurrentDataToEventThresholds();


	// TODO: Keep track of the previous sim cycle in the main loop. 
	// Return a vector of values for the average per environment for each state/mood variable that shows if it got better 
	// or worse since the last sim cycle with respect to countering the current S.I 
	return {};
}





// TODO: Check if values in EventLogs.json match the thresholds in WorldConfig.json for 
//     any expected HistoricEvents. 
void DataAnalyzer::compareCurrentDataToEventThresholds() {

}

// TODO: Make type T
double DataAnalyzer::averageEnvSpecificProperty(string envType, string propertyName) {

	double sum = 0;
	double envTypeCount = 0;
	for (Environment& env : world) {
		if (env.getType() == "WORK") {
			envTypeCount++;
			double profit = env.getEnvironmentSpecificVars()[propertyName].asDouble();
			sum += profit;
		}
	}

	double average = sum / envTypeCount;
	return average;
}

