#ifndef PAYROLL_BROWERALLEMPLOYEE_H_
#define PAYROLL_BROWERALLEMPLOYEE_H_

#include "transactions.h"
#include <map>
#include "employee.h"
#include "transaction.h"

class TRANSACTIONSAPI CBrowerAllEmployee :
	public Transaction
{
public:
	CBrowerAllEmployee();
public:
	virtual ~CBrowerAllEmployee();
	virtual void Execute();

	std::map<int, Employee*> GetEmployees() const { return itsEmployees; }

private:
	std::map<int, Employee*> itsEmployees;
};

#endif
