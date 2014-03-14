#ifndef PAYROLL_SALARIEDCLASSIFICATION_H_
#define PAYROLL_SALARIEDCLASSIFICATION_H_

#include "paymentclassification.h"
#include "classifications.h"

class CLASSIFICATIONSAPI SalariedClassification :
	public PaymentClassification {
public:
	SalariedClassification(double salaried);
	virtual ~SalariedClassification();

	double GetSalary() { return itsSalaried; }

	virtual double CalculatePay( PayCheck &pc );

private:
	double itsSalaried;
}; 

#endif