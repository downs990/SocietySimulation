#pragma once


#include "Environment.h"
#include <json\value.h>
#include <json\json.h>


class DataAnalyzer
{
public:
	DataAnalyzer();
	Json::Value getEventLogs();
	vector<string> updateEventLogs(vector<Environment> world);
	void compareCurrentDataToEventThresholds();
private:
	Json::Value currentEventLogs;


};

