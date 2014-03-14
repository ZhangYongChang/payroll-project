#ifndef PAYROLL_PAYMENTCLASSIFICATION_H_
#define PAYROLL_PAYMENTCLASSIFICATION_H_

#include "core.h"

class PayCheck;

class COREAPI PaymentClassification {
public:
	PaymentClassification();
	virtual ~PaymentClassification();

	virtual double CalculatePay(PayCheck &pc) = 0;
};

#endif