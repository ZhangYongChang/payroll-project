#ifndef PAYROLL_PAYMENTSCHEDULE_H_
#define PAYROLL_PAYMENTSCHEDULE_H_

#include "core.h"

class Date;

class COREAPI PaymentSchedule {
public:
	PaymentSchedule();
	virtual ~PaymentSchedule();

	virtual bool IsPayDate( const Date &date ) = 0;
};

#endif

