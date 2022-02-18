#pragma once


#include "Environment.h"
#include <json\value.h>
#include <json\json.h>


class DataAnalyzer
{
public:
	DataAnalyzer(vector<Environment> world);
	Json::Value getEventLogs();
	void updateEventLogs();
	void compareCurrentDataToEventThresholds();
private:
	Json::Value currentEventLogs;


};

