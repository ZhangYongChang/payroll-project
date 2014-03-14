#ifndef PAYROLL_MONTHSCHEDULE_H_
#define PAYROLL_MONTHSCHEDULE_H_

#include "schedules.h"
#include "paymentschedule.h" 

class SCHEDULESAPI MonthlySchedule :
	public PaymentSchedule {
public:
	MonthlySchedule();
	virtual ~MonthlySchedule();

	virtual bool IsPayDate( const Date &date );
}; 

#endif