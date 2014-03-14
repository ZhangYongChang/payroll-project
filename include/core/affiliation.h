#ifndef PAYROLL_AFFILIATION_H_
#define PAYROLL_AFFILIATION_H_

#include "core.h"

class COREAPI Affiliation
{
public:
	Affiliation();
public:
	virtual ~Affiliation();

	virtual double CalculateDeductions() = 0;
};

#endif