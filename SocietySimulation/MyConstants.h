#pragma once 

 
// TODO: How to make these global ??? Why would that be bad??? What's the best alternative ????
//static time_t *myCurrentDateTime;
//static struct tm *myDateTimeStruct;

static int const SECONDS_IN_HOUR = 3600;

enum class StateOfHealth {
	HEALTHY,
	DIABETES,
	OBESITY,
	PANDEMIC_VIRUS
};



// NOTE: This function is not used anywhere. It's just a nice reminder 
//       of how to use the "time_t" and "struct tm" object types. 
static void notesSection(time_t dateA, time_t dateB) {


	// Date time_t:
	//		 - Useful for deriving struct tm
	struct tm myDateTimeStruct;
	localtime_s(&myDateTimeStruct, &dateB);
	//       - Also, useful for offsetting date by specific hours.
	time_t nowB = dateB;
	nowB -= (SECONDS_IN_HOUR * 96);// 96 hours ago 


	// Date struct tm:
	//		 - Useful for deriving year, month, day, hours, etc. 
	int hourA = myDateTimeStruct.tm_hour, hourB = myDateTimeStruct.tm_hour;
	int dayA = myDateTimeStruct.tm_mday, dayB = myDateTimeStruct.tm_mday;
	int monthA = 1 + myDateTimeStruct.tm_mon, monthB = 1 + myDateTimeStruct.tm_mon;
	int yearA = 1900 + myDateTimeStruct.tm_year, yearB = 1980 + myDateTimeStruct.tm_year;


}


// Pre-Condition: A < B 
// Post-Condition: Hours difference calculated and returned. 
static int calculateHoursDifference(time_t dateA, time_t dateB) {
 	   
	return difftime(dateB, dateA) / SECONDS_IN_HOUR;
	 
}


 