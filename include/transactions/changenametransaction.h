#ifndef PAYROLL_CHANGENAMETRANSACTION_H_
#define PAYROLL_CHANGENAMETRANSACTION_H_

#include "changeemployeetransaction.h"

#include <string> 

class TRANSACTIONSAPI ChangeNameTransaction :
	public ChangeEmployeeTransaction
{
public:
	ChangeNameTransaction(int empid, std::string name);

	virtual ~ChangeNameTransaction();
	virtual void Change(Employee *e);

private:
	std::string itsName;
}; 

#endif