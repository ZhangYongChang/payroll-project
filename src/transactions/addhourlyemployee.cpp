#include "addhourlyemployee.h"

#include "hourlyclassification.h"
#include "weeklyschedule.h"
#include "mailmethod.h"
 
AddHourlyEmployee::AddHourlyEmployee( int empid, 
									 const std::string &name, 
									 const std::string &address, 
									 double hourly )
	: AddEmployeeTransaction(empid, name,address),
	itsHourly(hourly) {
}

AddHourlyEmployee::~AddHourlyEmployee() {
}

PaymentMethod * AddHourlyEmployee::GetPayMethod() const {
	PaymentMethod * pm(new MailMethod());
	return pm;
}

PaymentClassification * AddHourlyEmployee::GetClassification() const {
	PaymentClassification * pc(new HourlyClassification(itsHourly));
	return pc;
}

PaymentSchedule * AddHourlyEmployee::GetSchedule() const {	
	PaymentSchedule * ps(new WeeklySchedule());
	return ps;
} 