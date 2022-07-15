#include "DataAnalyzer.h" 

DataAnalyzer::DataAnalyzer(EnvironmentManager envManager) : world(envManager.allEnvironments) {
	worldConfigJSON = envManager.worldConfigJSON;

	runningEventLogsJSON = getEventLogs();

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
	ifstream file(EVENT_LOGS_PATH);

	// check if there is any error in getting data from the json file 
	if (!reader.parse(file, eventLogsJSON)) {
		cout << reader.getFormattedErrorMessages();
	}
	 
	return eventLogsJSON;
}


// TODO: Loop through world and check each persons state/mood variables and evnironment and update
//     EventLogs.json data with the current running values for expected thresholds. 
vector<string> DataAnalyzer::updateEventLogs() {


	checkFirstWorldCountry(); 

	

	// Write to "EventLogs.json"
	ofstream myfile;
	myfile.open(EVENT_LOGS_PATH);
	myfile << runningEventLogsJSON;
	myfile.close();



	// TODO: Keep track of the previous sim cycle in the main loop. 
	// Return a vector of values for the average per environment for each state/mood variable that shows if it got better 
	// or worse since the last sim cycle with respect to countering the current S.I 
	return {};
}




// TODO: Eventually, remove condition for checking only school envs. When people are 
// able to move to different envs, the ones that are educated in school will be moved 
// all over the place. So, you'll have to check each env.
void DataAnalyzer::checkFirstWorldCountry() {
	 

	Json::Value& thresholds = runningEventLogsJSON["HistoricEvents"][0]["Thresholds"];
	string currentAverageEducation = "ELEMENTARY"; 
	int sumKnowledge = 0, totalPopulation = 0;
	float sumProfits = 0;

	for (Environment& env : world) {
	
		if (env.getType() == "SCHOOL") {
			 
			for (Person& p : *env.getPopulation()) {
				sumKnowledge += p.getKnowledgeScore();
			}

			totalPopulation += env.getPopulation()->size();
			int averageKnowledgeScore = sumKnowledge / totalPopulation;
			string education = getEducationLevel(averageKnowledgeScore);
			currentAverageEducation = education;
			cout << "AverageKnowledgeScore: " << averageKnowledgeScore << "  Education: " << education << "\n";
		} 
		if (env.getType() == "WORK") {

			Json::Value envSpecificVars = env.getEnvironmentSpecificVars();
			sumProfits += envSpecificVars["QuarterlyProfitDollars"].asFloat();
			cout << "GrossDomesticProduct: " << sumProfits <<  "\n";
		}
	}
	
	// Update JSON 
	thresholds["AverageEducationLevel"] = currentAverageEducation;
	thresholds["GrossDomesticProduct"] = sumProfits;

	Json::Value firstWorldConditions = worldConfigJSON["HistoricEvents"][0]["Thresholds"];
	float grossDomesticProduct = firstWorldConditions["GrossDomesticProduct"].asFloat();
	string averageEducation = firstWorldConditions["AverageEducationLevel"].asString();

	if (currentAverageEducation == averageEducation && sumProfits >= grossDomesticProduct) {
		logSimData("Historic Event Achieved:   FIRST_WORLD_COUNTRY ");
	}
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

