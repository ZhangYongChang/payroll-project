#ifndef PAYROLL_WEEKLISCHEDULE_H_
#define PAYROLL_WEEKLISCHEDULE_H_

#include "schedules.h"
#include "paymentschedule.h" 

class SCHEDULESAPI WeeklySchedule :
	public PaymentSchedule {
public:
	WeeklySchedule();
public:
	virtual ~WeeklySchedule();

	virtual bool IsPayDate( const Date &date );
}; 

#endif