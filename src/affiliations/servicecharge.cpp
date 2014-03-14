#include "servicecharge.h" 

ServiceCharge::ServiceCharge(const Date& date, const double& amount) 
	: itsDate(date),
	itsAmount(amount) {
}

ServiceCharge::ServiceCharge( const ServiceCharge& charge ) 
	: itsDate(charge.itsDate),
	itsAmount(charge.itsAmount){

}

ServiceCharge::~ServiceCharge() {
}

 