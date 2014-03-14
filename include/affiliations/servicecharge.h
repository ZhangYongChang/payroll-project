#ifndef PAYROLL_SERVICECHARGE_H_
#define PAYROLL_SERVICECHARGE_H_

#include "affiliations.h"
#include "date.h" 

class AFFILIATIONSAPI ServiceCharge
{
public:
	ServiceCharge(const Date& date, const double& amount);
	ServiceCharge( const ServiceCharge& charge);

	Date GetDate() const { return itsDate; }
	double GetAmount() const { return itsAmount; }

public:
	virtual ~ServiceCharge();

private:
	Date itsDate;
	double itsAmount;
}; 

#endif