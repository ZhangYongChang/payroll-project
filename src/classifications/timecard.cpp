#include "timecard.h" 

TimeCard::~TimeCard() {
}

TimeCard::TimeCard( const Date date, const int& hours ) 
	: itsDate(date),
	itsHours(hours) {
}

TimeCard::TimeCard( const TimeCard& timecard ) 
	: itsDate(timecard.itsDate),
	itsHours(timecard.itsHours) {
}

 
