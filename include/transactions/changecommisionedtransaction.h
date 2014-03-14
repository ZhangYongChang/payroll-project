#ifndef PAYROLL_CHANGECOMMISIONEDTRANSACTION_H_
#define PAYROLL_CHANGECOMMISIONEDTRANSACTION_H_

#include "changeclassificationtransaction.h"

class TRANSACTIONSAPI ChangeCommisionedTransaction :
	public ChangeClassificationTransaction
{
public:
	ChangeCommisionedTransaction(const int empid, const double& salaried, const double& rate);
public:
	virtual ~ChangeCommisionedTransaction();
	virtual PaymentClassification *GetPaymentClassification() const;
	virtual PaymentSchedule *GetPaymentSchedule() const;

private:
	double itsSalaried;
	double itsRate;
};

#endif
