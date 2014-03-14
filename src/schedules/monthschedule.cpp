#include "monthschedule.h"
#include "date.h"

MonthlySchedule::MonthlySchedule() {
}

MonthlySchedule::~MonthlySchedule() {
}

bool MonthlySchedule::IsPayDate( const Date &date ) {
	int day = date.GetDay();

	if (day == 15) {
		return true;
	} else {
		return false;
	}
}
