#include "weeklyschedule.h"

#include "date.h"

WeeklySchedule::WeeklySchedule() {
}

WeeklySchedule::~WeeklySchedule() {
}

bool WeeklySchedule::IsPayDate( const Date &date )
{
	if (date.GetDay() % 7 == 0)	{
		return true;
	}

	return false;
}