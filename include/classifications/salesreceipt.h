#ifndef PAYROLL_SALESRECEIPT_H_
#define PAYROLL_SALESRECEIPT_H_

#include "classifications.h"
#include "date.h"

class CLASSIFICATIONSAPI SalesReceipt {
public:
	SalesReceipt(const Date& date, const double& amount);
	SalesReceipt(const SalesReceipt& receipt);

	Date GetDate() const { return itsDate; }
	double GetAmount() const { return itsAmount; }

public:
	virtual ~SalesReceipt();

private:
	Date itsDate;
	double itsAmount;
};

#endif