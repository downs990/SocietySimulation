#include "Person.h" 




Person::Person(int id, struct tm currentDateTime) {
	this->id = id;
	this->dailySchedule = Schedule();
	this->healthState = StateOfHealth::HEALTHY;

	// TODO: Init dsspg and disciplined 
	this->lastSlept = currentDateTime;    
	this->lastAte = currentDateTime;      
	 

	this->isEmployed = true;

}


void Person::setHealthState(StateOfHealth healthState) {
	this->healthState = healthState;
}

StateOfHealth Person::getHealthState() {
	return this->healthState;
}


// If dsspg reaches 10 then happy = 0 
// If dsspg > 10 then happy < 0 
double Person::getHappy(struct tm currentDateTime) {
	
	// Converts dsspg to percentage and subtracts that percentage of f from f
	double f = getFocus(currentDateTime);
 	double happy = f - ((dsspg * 0.10) * f);

	return happy;
}

// Pre-Condition: A < B 
//double Person::calculateHoursDifference(struct tm dateA, struct tm dateB) {
//
//
//	int const SECONDS_IN_HOUR = 3600;
//
//	int hourA = dateA.tm_hour;
//	int dayA = dateA.tm_mday;
//	int monthA = 1 + dateA.tm_mon;
//	int yearA = 1900 + dateA.tm_year;
//
//
//	int hourB = dateB.tm_hour;
//	int dayB = dateB.tm_mday;
//	int monthB = 1 + dateB.tm_mon;
//	int yearB = 1900 + dateB.tm_year;
//
//	// TODO: Calculate B - A and return difference in hours. 
//
//	return 0;

//}

// If a >= many && b >= many   c = very low
// If a >= many || b >= many   c = low 
// Else						   c = high  
double Person::getFocus(struct tm currentDateTime) {

	int focus = 89;
	// TODO: Set focus to random value between 0.89-0.99


	//int MANY_HOURS_NO_SLEEP = 15; // range {0 - 96}  // 4 days 
	//int MANY_HOURS_NO_EAT = 5;    // range {0 - 168} // 7 days 
	int MAX_HOURS_NO_SLEEP = 96;
	int MAX_HOURS_NO_EAT = 168;

	// TODO: Uncomment this after testing.
	//int a = this->getHoursSinceSlept(currentDateTime);
	//int b = this->getHoursSinceAte(currentDateTime);
 
	//          sleep          food 
	// 89 - (2(96 * 0.10) + ((4 * 168) * 0.10))   = 2.6  // MAX 
	// 89 - (2(48 * 0.10) + ((6 * 84) * 0.10))    = 28   // MEDIAN
	// 89 - (2(15 * 0.10) + ((60 * 5) * 0.10))    = 56   // MIN  
	
	// ^
	// Weights range { 60 - 4 }      B Range { 5 - 168 }

					
	double c1 = 0.6840; // 54 / 79          60 - 6 = 54     84 - 5 = 79 
	double c2 = 0.0238; // 2 / 84           6 - 4 = 2       168 - 84 = 84
	double c3 = 0.5714; // 96 / 168 

	double b = 0;
	double a = 0;
	// TODO: Remove this loop after testing.
	for (int i = b; i <= 168; i++) {

		b = i;   
		a += c3; 

		// focusWeight    { 60 - 4 }  
		// hoursNoEat     { 5 - 168} 
		double fWeightHigh = (6.0 - (b - (MAX_HOURS_NO_EAT / 2.0)) * c2);
		double fWeightLow = (6.0 + ((MAX_HOURS_NO_EAT / 2.0) - b) * c1); 

		double chosenWeight =  (b >= (MAX_HOURS_NO_EAT / 2)) ? fWeightHigh : fWeightLow;
 



		// TODO: Fix formula to make these values non-negative  
		//     a: 10.2852    b : 17    Weight : 51.828    Focus : -1
		//          .
		//          .
		//          .
		//     a : 44.5692    b : 77    Weight : 10.788    Focus : -2



		focus = 89 - ((2 * a * 0.10) + (chosenWeight * b * 0.10));
		cout << " a: " << a << "    b: " << b << "    Weight: " << chosenWeight << "    Focus: " << focus << "\n";
	}

	//cout << "\nWorld: " << world[0].toString() << "\n";
	 

	 /*
			 Examples: 
		89 - (2(96 * 0.10) + ((4 * 168) * 0.10))   = 2.6

		89 - (2(91 * 0.10) + ((4.1 * 158) * 0.10)) = 5

		89 - (2(85 * 0.10) + ((4.3 * 147 ) * 0.10)) = 9

		89 - (2(74 * 0.10) + ((4.6 * 126 ) * 0.10))  = 16



		89 - (2(48 * 0.10) + ((6 * 84) * 0.10))    = 28



		89 - (2(32 * 0.10) + ((9 * 42) * 0.10))    = 44

		89 - (2(24 * 0.10) + ((16 * 21) * 0.10))   = 50

		89 - (2(15 * 0.10) + ((60 * 5) * 0.10))    = 56
	
	*/
	 

	return focus;
}
 
void Person::setEmployment(bool employmentStatus) {
	this->isEmployed = employmentStatus;
}

bool Person::getEmployment() {
	return this->isEmployed;
}

void Person::addTaskToSchedule(string repeatDays, string startTime, string endTime, string locationName) {
	this->dailySchedule.addTask(repeatDays, startTime, endTime, locationName);
}

void Person::markTaskAsComplete(string taskName) {}


Schedule Person::getSchedule() {
	return this->dailySchedule;
}
 
 
 
void Person::setLastSlept(struct tm lastSlept) { this->lastSlept; }
int Person::getHoursSinceSlept(struct tm currentDateTime) { return 0; }
int Person::getHoursSlept(struct tm currentDateTime) { return 0; }

 
void Person::setLastAte(struct tm lastAte) { this->lastAte; }
int Person::getHoursSinceAte(struct tm currentDateTime) { return 0; }
int Person::getHoursSpentEating(struct tm currentDateTime) { return 0; }


string Person::toString() {
	// TODO: Pass current tm currentDateTime to this function.
	 
	ostringstream os;
	os << "\nId: " << this->id <<
		"  isEmployed: " << this->isEmployed;
	//	"  Happy: " << this->getHappy() << 
	//	"  Focus: " << this->getFocus() <<
	//	"  HoursSinceSlept: " << this->lastSlept <<
	//	"  HoursSinceAte: " << this->lastAte;
 
	// TODO: How to convert struct to string ?
	return os.str();
}

