#pragma once


#include "Environment.h"
#include <json\value.h>
#include <json\json.h>


class DataAnalyzer
{
public:
	DataAnalyzer(vector<Environment>& currentWorld);
	Json::Value getEventLogs();
	vector<string> updateEventLogs();
	void compareCurrentDataToEventThresholds();
	double averageEnvSpecificProperty(string envType, string propertyName);

private:
	vector<Environment>& world;
	Json::Value currentEventLogs;


};

