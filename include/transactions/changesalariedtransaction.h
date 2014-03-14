#ifndef CHANGESALARIEDTRANSACTION_H_
#define CHANGESALARIEDTRANSACTION_H_

#include "changeclassificationtransaction.h" 

class TRANSACTIONSAPI ChangeSalariedTransaction 
	: public ChangeClassificationTransaction
{
public:
	ChangeSalariedTransaction(int empid, double salary);
	virtual ~ChangeSalariedTransaction();

	virtual PaymentClassification *GetPaymentClassification() const;
	virtual PaymentSchedule *GetPaymentSchedule() const;

private:
	double itsSalaried;
}; 

#endif