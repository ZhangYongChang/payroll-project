#ifndef PAYROLL_PAYMENTMETHOD_H_
#define PAYROLL_PAYMENTMETHOD_H_

#include "core.h"

class PayCheck;

class COREAPI PaymentMethod {
public:
	PaymentMethod();
	virtual ~PaymentMethod();

	virtual void Pay(PayCheck &pc) = 0;
}; 

#endif