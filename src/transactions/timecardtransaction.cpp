#include "timecardtransaction.h"
#include "employee.h"
#include "hourlyclassification.h"
#include "proxy.h"
#include "databaseproxy.h"

TimeCardTransaction::TimeCardTransaction( const int& empid, 
										 const Date& date, 
										 const int& hours ) 
	: itsEmpid(empid),
	itsDate(date),
	itsHours(hours) {
}

TimeCardTransaction::~TimeCardTransaction() {
}

void TimeCardTransaction::Execute() {
	Employee *e = DBPROXY->GetEmployee(itsEmpid);
	if (e == 0) {
		return;
	} else {
		PaymentClassification *pc = e->GetPaymentClassification();
		if (pc == 0) {
			return;
		} else {
			HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
			if (hc == 0) {
				return;
			} else {
				TimeCard timecard(itsDate, itsHours);
				hc->AddTimeCard(timecard);
			}
		}
	}
}
