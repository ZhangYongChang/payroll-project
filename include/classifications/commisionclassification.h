#ifndef PAYROLL_COMMISIONCLASSIFICATION_H_
#define PAYROLL_COMMISIONCLASSIFICATION_H_

#include "paymentclassification.h"
#include "classifications.h"
#include "salesreceipt.h"

#include <vector> 

class CLASSIFICATIONSAPI CommisionClassification :
	public PaymentClassification
{
public:
	CommisionClassification(const double salaried, const double rate);
	virtual ~CommisionClassification();

	double GetSalaried() const { return itsBasicSalaried; }
	double GetRate() const { return itsRate; }

	std::vector<SalesReceipt> GetSalesReceipts() const { return *itsSalesReceipt; }
	SalesReceipt GetSalesReceipt(const Date& date);

	void AddSalesReceipt(const SalesReceipt& receipt);

	virtual double CalculatePay( PayCheck &pc );

private:
	double itsBasicSalaried;
	double itsRate;

    typedef std::vector<SalesReceipt> SalesReceiptList;

	SalesReceiptList *itsSalesReceipt;
}; 

#endif