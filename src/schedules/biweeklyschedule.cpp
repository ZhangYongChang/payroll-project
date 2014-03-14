#include "biweeklyschedule.h"
#include "date.h"

BiweeklySchedule::BiweeklySchedule() {
}

BiweeklySchedule::~BiweeklySchedule() {
}

bool BiweeklySchedule::IsPayDate( const Date &date ) {
	if (date.GetDay()%14 == 0) {
		return true;
	} else {
		return false;
	}
}