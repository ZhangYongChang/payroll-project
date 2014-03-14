#ifndef PAYROLL_UNIONAFFILIATION_H_
#define PAYROLL_UNIONAFFILIATION_H_

#include "affiliations.h"
#include "affiliation.h"
#include "servicecharge.h"

#include <vector>

class AFFILIATIONSAPI UnionAffiliation :
	public Affiliation {
public:
	UnionAffiliation();
	virtual ~UnionAffiliation();
	void AddSericeCharge(const ServiceCharge& charge);
	ServiceCharge GetServiceCharge(const Date& date) const;
	virtual double CalculateDeductions();

private:
	typedef std::vector<ServiceCharge> ServiceChargeListType;
	ServiceChargeListType *itsServiceCharge;
}; 

#endif