#ifndef PAYCHECK_H_
#define PAYCHECK_H_

#include "core.h"

#include "date.h" 

class COREAPI PayCheck
{
public:
	PayCheck(Date &date);
	virtual ~PayCheck();

	void SetGrossPay(double itsGrossPay);
	void SetDeductions(double itsDeductions);
	void SetNetPay(double itsNetPay);
	void SetName( const std::string &name );

	double GetGrossPay() const;
	double GetDeductions() const;
	double GetNetPay() const;
	std::string GetName() const;

private:
	double itsGrossPay;
	double itsDeductions;
	double itsNetPay;

	std::string itsName;

	Date itsDate;
}; 

#endif