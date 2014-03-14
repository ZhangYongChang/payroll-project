#ifndef PAYROLL_CHANGEADDRESSTREANSACTION_H_
#define PAYROLL_CHANGEADDRESSTREANSACTION_H_

#include "changeemployeetransaction.h"

#include <string> 

class TRANSACTIONSAPI ChangeAddressTransaction :
	public ChangeEmployeeTransaction {
public:
	ChangeAddressTransaction(int empid, const std::string& address);

	virtual ~ChangeAddressTransaction();

	virtual void Change(Employee *e);

private:
	std::string itsAddress;
};

#endif