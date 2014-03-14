#ifndef PAYROLL_TIMECARDTRANSACTION_H_
#define PAYROLL_TIMECARDTRANSACTION_H_

#include "transactions.h"
#include "transaction.h"
#include "date.h" 

class TRANSACTIONSAPI TimeCardTransaction :
	public Transaction {
public:
	TimeCardTransaction( const int& empid, const Date& date, const int& hours );
public:
	virtual ~TimeCardTransaction();
	virtual void Execute();

private:
	int itsEmpid;
	Date itsDate;
	int itsHours;	
}; 

#endif