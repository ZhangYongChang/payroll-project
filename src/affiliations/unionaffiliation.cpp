#include "unionaffiliation.h"

UnionAffiliation::UnionAffiliation() {
	itsServiceCharge = new ServiceChargeListType();
}

UnionAffiliation::~UnionAffiliation() {
	delete itsServiceCharge;
}

void UnionAffiliation::AddSericeCharge( const ServiceCharge& charge ) {
	itsServiceCharge->push_back(charge);
}

ServiceCharge UnionAffiliation::GetServiceCharge( const Date& date ) const {
	for (std::vector<ServiceCharge>::const_iterator it = itsServiceCharge->begin();
		it != itsServiceCharge->end();
		++it) {
			if (it->GetDate() == date) {
				return *it;
			}
	}

	ServiceCharge sc(date , 0.00);
	return sc;
}

double UnionAffiliation::CalculateDeductions()
{
	double amount = 0.0;

	for (ServiceChargeListType::const_iterator it = itsServiceCharge->begin();
		it != itsServiceCharge->end();
		++it) {
		amount += it->GetAmount();
	}

	return amount;
}