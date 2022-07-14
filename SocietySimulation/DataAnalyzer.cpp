#include "DataAnalyzer.h" 

DataAnalyzer::DataAnalyzer(EnvironmentManager envManager) : world(envManager.allEnvironments) {
	worldConfigJSON = envManager.worldConfigJSON;

	runningEventLogsJSON = {};

	// TOOD: Remove "EventLogs.json" and just keep track of those thresholds in a variable. 
	Json::Value historicEventThresholds = {
		// Initialized running threashold values. 
		// {
		//  "Name": "FirstWorldCountry",
		//	  "Thresholds" : {
		//		"GrossDomesticProduct": 0,
		//		"AverageEducationLevel" : "ELEMENTARY"
		//	  }
		// }

		// .... 
	};
	 

}


// TODO: Read all events from EventLogs.json and store it in currentEventsLogs variable
Json::Value DataAnalyzer::getEventLogs() {

	Json::Reader reader;
	Json::Value eventLogsJSON;

	//opening file using fstream
	ifstream file("C:\\Users\\downs\\Desktop\\VisualStudioWorkspace\\SocietySimulation\\SocietySimulation\\EventLogs.json");

	// check if there is any error in getting data from the json file 
	if (!reader.parse(file, eventLogsJSON)) {
		cout << reader.getFormattedErrorMessages();
	}

	runningEventLogsJSON = eventLogsJSON;
	return runningEventLogsJSON;
}


// TODO: Loop through world and check each persons state/mood variables and evnironment and update
//     EventLogs.json data with the current running values for expected thresholds. 
vector<string> DataAnalyzer::updateEventLogs() {


	string currentAverageEducation = checkForFirstWorldCountry();

	// Update JSON
	runningEventLogsJSON["HistoricEvents"][0]["Thresholds"]["AverageEducationLevel"] = currentAverageEducation;

	// TODO: Figure out why the below fields are deleted when the .json file is updated. 
/*
	{
		"HistoricEvents": [
		{
			"Name": "FirstWorldCountry",
				"Thresholds" : {
				"GrossDomesticProduct": 0,
					"AverageEducationLevel" : "ELEMENTARY"
			}
		},
	{
	  "Name": "HighQualityOfHealth",
	  "Thresholds" : { "<RUNNING-CURRENT-THRESHOLD-VALUES-HERE>": 0 }
	},
	{
	  "Name": "SocialEquality",
	  "Thresholds" : { "<RUNNING-CURRENT-THRESHOLD-VALUES-HERE>": 0 }
	}
	] }
*/

	// Write to "EventLogs.json"
	ofstream myfile;
	myfile.open("C:\\Users\\downs\\Desktop\\VisualStudioWorkspace\\SocietySimulation\\SocietySimulation\\EventLogs.json");
	myfile << runningEventLogsJSON;
	myfile.close();



	// TODO: Keep track of the previous sim cycle in the main loop. 
	// Return a vector of values for the average per environment for each state/mood variable that shows if it got better 
	// or worse since the last sim cycle with respect to countering the current S.I 
	return {};
}



 



// TODO: Check if values in EventLogs.json match the thresholds in WorldConfig.json for 
//     any expected HistoricEvents. 
string DataAnalyzer::checkForFirstWorldCountry() {

	// TODO: Actually compare these thresholds to "runningEventLogsJSON"
	//Json::Value firstWorldConditions = worldConfigJSON["HistoricEvents"][0]["Thresholds"];
	//double grossDomesticProduct = firstWorldConditions["GrossDomesticProduct"].asDouble();
	//string averageEducation = firstWorldConditions["AverageEducationLevel"].asString();

	string currentAverageEducation = "ELEMENTARY";

	int averageKnowledgeScore = 0;
	int sumKnowledge = 0;
	int sumPopulation = 0;

	for (Environment& env : world) {
	
		if (env.getType() == "SCHOOL") {
					 
			for (Person& p : *env.getPopulation()) {
				sumKnowledge += p.getKnowledgeScore();
			}

			sumPopulation += env.getPopulation()->size();

			averageKnowledgeScore = sumKnowledge / sumPopulation;
			 
			string education = getEducationLevel(averageKnowledgeScore);
			cout << "AverageKnowledgeScore: " << averageKnowledgeScore << "  Education: " << education << "\n";
			currentAverageEducation = education;
		} 
	}

	return currentAverageEducation;
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

