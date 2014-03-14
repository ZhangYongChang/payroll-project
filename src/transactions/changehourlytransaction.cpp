#include "changehourlytransaction.h"

#include "hourlyclassification.h"
#include "weeklyschedule.h"

 
ChangeHourlyTransaction::ChangeHourlyTransaction( int empid, double hourlyRate ) 
	: ChangeClassificationTransaction(empid), 
	itsHourlyRate(hourlyRate) {
}

ChangeHourlyTransaction::~ChangeHourlyTransaction() {
}

PaymentClassification *ChangeHourlyTransaction::GetPaymentClassification() const {
	PaymentClassification *pc = new HourlyClassification(itsHourlyRate);
	return pc;
}

PaymentSchedule *ChangeHourlyTransaction::GetPaymentSchedule() const {
	PaymentSchedule *ps = new WeeklySchedule();
	return ps;
}