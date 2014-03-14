#ifndef PAYROLL_DELETEEMPLOYEETRANSACTION_H_
#define PAYROLL_DELETEEMPLOYEETRANSACTION_H_

#include "transactions.h"
#include "transaction.h" 

class TRANSACTIONSAPI DeleteEmployeeTransaction :
	public Transaction
{
public:
	DeleteEmployeeTransaction(const int empid);
	virtual ~DeleteEmployeeTransaction();

	virtual void Execute();

private:
	int itsEmpid;
}; 

#endif