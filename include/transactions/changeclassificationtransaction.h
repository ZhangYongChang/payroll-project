#ifndef PAYROLL_CHANGECLASSIFICATIONTRANSACTION_H_
#define PAYROLL_CHANGECLASSIFICATIONTRANSACTION_H_

#include "changeemployeetransaction.h"

class PaymentClassification;
class PaymentSchedule;

class TRANSACTIONSAPI ChangeClassificationTransaction :
	public ChangeEmployeeTransaction {
public:
	ChangeClassificationTransaction(int empid);

	virtual ~ChangeClassificationTransaction();

	virtual PaymentClassification *GetPaymentClassification() const = 0;
	virtual PaymentSchedule *GetPaymentSchedule() const = 0;

	virtual void Change(Employee *e);
}; 

#endif
