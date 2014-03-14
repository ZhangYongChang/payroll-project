#ifndef PAYROLL_BIWEEKLYSCHEDULE_H_
#define PAYROLL_BIWEEKLYSCHEDULE_H_

#include "schedules.h"
#include "paymentschedule.h" 

class SCHEDULESAPI BiweeklySchedule :
	public PaymentSchedule {
public:
	BiweeklySchedule();

	virtual ~BiweeklySchedule();

	virtual bool IsPayDate( const Date &date );
};

#endif