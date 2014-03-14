#ifndef PAYROLL_CHANGEMPLOYEETREANSACTION_H_
#define PAYROLL_CHANGEMPLOYEETREANSACTION_H_

#include "transactions.h"
#include "transaction.h"

class Employee;

class TRANSACTIONSAPI ChangeEmployeeTransaction :
	public Transaction {
public:
	ChangeEmployeeTransaction(int empid);

	virtual ~ChangeEmployeeTransaction();

	virtual void Execute();

	virtual void Change(Employee *e) = 0;

protected:
	int itsEmpid;
};

#endif