#include "paycheck.h"

void PayCheck::SetDeductions( double itsDeductions ) {
	this->itsDeductions = itsDeductions;
}

void PayCheck::SetGrossPay( double itsGrossPay ) {
	this->itsGrossPay = itsGrossPay;
}

void PayCheck::SetNetPay( double itsNetPay ) {
	this->itsNetPay = itsNetPay;
}

double PayCheck::GetGrossPay() const {
	return itsGrossPay;
}

double PayCheck::GetDeductions() const {
	return itsDeductions;
}

double PayCheck::GetNetPay() const {
	return itsNetPay;
}

PayCheck::PayCheck( Date &date ) : itsDate(date), itsName("") {
}

PayCheck::~PayCheck() {
}

void PayCheck::SetName( const std::string &name ) {
	itsName = name;
}

std::string PayCheck::GetName() const {
	return itsName;
}

 