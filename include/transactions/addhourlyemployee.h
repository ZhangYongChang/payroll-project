#ifndef PATROLL_ADDHOURLYEMPLOYEE_H_
#define PATROLL_ADDHOURLYEMPLOYEE_H_

#include "addemployeetransaction.h"

class TRANSACTIONSAPI AddHourlyEmployee :
	public AddEmployeeTransaction
{
public:
	AddHourlyEmployee(const int empid, 
		const std::string &name, 
		const std::string &address, 
		const double hourly);
	virtual ~AddHourlyEmployee();

	virtual PaymentMethod *GetPayMethod() const;
	virtual PaymentClassification *GetClassification() const;
	virtual PaymentSchedule *GetSchedule() const;

private:
	double itsHourly;
};

#endif