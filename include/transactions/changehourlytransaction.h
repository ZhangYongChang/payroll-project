#ifndef PAYROLL_CHANGEHOURLYTRANSACTION_H_
#define PAYROLL_CHANGEHOURLYTRANSACTION_H_

#include "changeclassificationtransaction.h" 

class TRANSACTIONSAPI ChangeHourlyTransaction :
	public ChangeClassificationTransaction
{
public:
	ChangeHourlyTransaction(int empid, double hourlyRate);

	virtual ~ChangeHourlyTransaction();

	virtual PaymentClassification *GetPaymentClassification() const;
	virtual PaymentSchedule *GetPaymentSchedule() const;

private:
	double itsHourlyRate;
};

#endif
