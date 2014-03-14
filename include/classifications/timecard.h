#ifndef PAYROLL_TIMECARD_H_
#define PAYROLL_TIMECARD_H_

#include "classifications.h"

#include "date.h"

class CLASSIFICATIONSAPI TimeCard {
public:
	TimeCard( const Date date, const int& hours );
	TimeCard( const TimeCard& timecard );

	Date GetDate() const { return itsDate; }
	int GetHours() const { return itsHours; }
public:
	virtual ~TimeCard();

private:
	Date itsDate;
	int itsHours;
};

#endif


