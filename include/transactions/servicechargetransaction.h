#ifndef PAYROLL_SERVICECHARGETRANSACTION_H_
#define PAYROLL_SERVICECHARGETRANSACTION_H_

#include "transactions.h"
#include "transaction.h"
#include "date.h"

class TRANSACTIONSAPI ServiceChargeTransaction :
	public Transaction {
public:
	ServiceChargeTransaction( const int& memberId, const Date& date, const double& amount);

	Date GetDate() const { return itsDate; }
	double GetAmount() const { return itsAmount; }

public:
	virtual ~ServiceChargeTransaction();
	virtual void Execute();

private:
	int itsMemberId;
	Date itsDate;
	double itsAmount;	
}; 

#endif