#pragma once


#include "EnvironmentManager.h"
#include <json\value.h>
#include <json\json.h>


class DataAnalyzer
{
public:
	DataAnalyzer(EnvironmentManager envManager);
	Json::Value getEventLogs();
	vector<string> updateEventLogs();
	string checkForFirstWorldCountry();
	double averageEnvSpecificProperty(string envType, string propertyName);

private:
	vector<Environment>& world;
	Json::Value worldConfigJSON;
	Json::Value runningEventLogsJSON;


};

