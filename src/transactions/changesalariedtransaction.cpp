#include "changesalariedtransaction.h"

#include "salariedclassification.h"
#include "monthschedule.h" 

ChangeSalariedTransaction::ChangeSalariedTransaction( int empid, double salary ) 
	: ChangeClassificationTransaction(empid), itsSalaried(salary)
{
}

ChangeSalariedTransaction::~ChangeSalariedTransaction() {

}

PaymentClassification * ChangeSalariedTransaction::GetPaymentClassification() const
{
	PaymentClassification *pc = new SalariedClassification(itsSalaried);
	return pc;
}

PaymentSchedule * ChangeSalariedTransaction::GetPaymentSchedule() const
{
	PaymentSchedule *ps = new MonthlySchedule();
	return ps;
} 