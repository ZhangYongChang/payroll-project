#ifndef PAYROLL_ADDEMPLOYEETRANSACTION_H_
#define PAYROLL_ADDEMPLOYEETRANSACTION_H_

#include "transactions.h"
#include "transaction.h"

#include <string>

class PaymentClassification;
class PaymentSchedule;
class PaymentMethod;

class TRANSACTIONSAPI AddEmployeeTransaction :
	public Transaction {
public:
	AddEmployeeTransaction( int empid, 
        const std::string &name, 
        const std::string &address);

	virtual ~AddEmployeeTransaction();

	virtual PaymentMethod *GetPayMethod() const = 0;
	virtual PaymentClassification *GetClassification() const = 0;
	virtual PaymentSchedule *GetSchedule() const = 0;

	virtual void Execute();

private:
	int itsEmpid;
	std::string itsName;
	std::string itsAddress;
};

#endif