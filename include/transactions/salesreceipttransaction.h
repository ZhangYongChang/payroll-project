#ifndef PAYROLL_SALESRECEIPTTRANSACTION_H_
#define PAYROLL_SALESRECEIPTTRANSACTION_H_

#include "transactions.h"
#include "transaction.h"

#include "date.h" 

class TRANSACTIONSAPI SalesReceiptTransaction :
	public Transaction
{
public:
	SalesReceiptTransaction(const int& empid, const Date& date, 
		const double& amount);

	virtual ~SalesReceiptTransaction();
	virtual void Execute();

private:
	int itsEmpid;
	Date itsDate;
	double itsAmount;
}; 

#endif