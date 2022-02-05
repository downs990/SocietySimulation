#pragma once 

 
// TODO: How to make these global ??? Why would that be bad??? What's the best alternative ????
//static time_t *myCurrentDateTime;
//static struct tm *myDateTimeStruct;


enum class StateOfHealth {
	HEALTHY,
	DIABETES,
	OBESITY,
	PANDEMIC_VIRUS
};



// Pre-Condition: A < B 
// Post-Condition: Hours difference calculated and returned. 
static int calculateHoursDifference(struct tm dateA, struct tm dateB) {
	 


	int result = 0;
	int const SECONDS_IN_HOUR = 3600;

	int hourA = dateA.tm_hour;
	int dayA = dateA.tm_mday;
	int monthA = 1 + dateA.tm_mon;
	int yearA = 1900 + dateA.tm_year;


	int hourB = dateB.tm_hour;
	int dayB = dateB.tm_mday;
	int monthB = 1 + dateB.tm_mon;
	int yearB = 1900 + dateB.tm_year;


	if (yearA <= yearB) {
		if (monthA <= monthB) {
			if (dayA <= dayB) {


				// TODO: Fix this math. Test edge cases.
				int daysDifference = dayB - dayA;
				int hoursDifference = hourB - hourA;
				result = (daysDifference * 24) + hoursDifference;
			}
		}
	}

	return result;
}