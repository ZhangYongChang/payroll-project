#ifndef PAYROLL_ADDSALARIEDEMPLOYEE_H_
#define PAYROLL_ADDSALARIEDEMPLOYEE_H_

#include "addemployeetransaction.h"

class TRANSACTIONSAPI AddSalariedEmployee :
	public AddEmployeeTransaction
{
public:
	AddSalariedEmployee(const int empid,
		const std::string &name,
		const std::string &address,
		const double salary);

	virtual ~AddSalariedEmployee();

	virtual PaymentMethod *GetPayMethod() const;
	virtual PaymentClassification *GetClassification() const;
	virtual PaymentSchedule *GetSchedule() const;

private:
	double itsSalary;
};

#endif