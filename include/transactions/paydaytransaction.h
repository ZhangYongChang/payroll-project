#ifndef PAYDAYTRANSACTION_H_
#define PAYDAYTRANSACTION_H_

#include "transactions.h"
#include "transaction.h"

#include <map>

#include "date.h"

class PayCheck;

class TRANSACTIONSAPI PaydayTransaction :
	public Transaction
{
public:
	PaydayTransaction(Date &date);
	virtual ~PaydayTransaction();

	virtual void Execute();
	PayCheck *GetPayCheck(int empid);


private:
	Date paydate;

	std::map<int, PayCheck *> itsPaychecks;
};

 

#endif