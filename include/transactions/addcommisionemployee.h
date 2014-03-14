#ifndef PAYROLL_ADDCOMMISIONEMPLOYEE_H_
#define PAYROLL_ADDCOMMISIONEMPLOYEE_H_

#include "addemployeetransaction.h"

class TRANSACTIONSAPI AddCommisionEmployee :
	public AddEmployeeTransaction {
public:
	AddCommisionEmployee(const int empid, 
		const std::string &name, 
		const std::string &address,
		const double salaried, 
		const double rate);

	virtual ~AddCommisionEmployee();

	virtual PaymentMethod *GetPayMethod() const;
	virtual PaymentClassification *GetClassification() const;
	virtual PaymentSchedule *GetSchedule() const;

private:
	double itsBasicSalaried;
	double itsRate;
};

#endif