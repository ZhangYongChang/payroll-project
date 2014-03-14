#include "employee.h"

#include "paymentclassification.h"
#include "paymentschedule.h"
#include "paymentmethod.h"
#include "affiliation.h"
#include "paycheck.h"

Employee::Employee( const int empid, 
				   const std::string &name, 
				   const std::string &address )
	: itsEmpid(empid),
	itsName(name),
	itsAddress(address),
	itspc(0),
	itspm(0),
	itsps(0), itsaf(NULL) {
}

Employee::~Employee() {
}

void Employee::SetPaymentClassification( PaymentClassification * pc ) {
	itspc = pc;
}

void Employee::SetPaymentSchedule( PaymentSchedule * ps ) {
	itsps = ps;
}

void Employee::SetPaymentMethod( PaymentMethod * pm ) {
	itspm = pm;
}

void Employee::SetAffilication( Affiliation * af ) {
	itsaf = af;
}

void Employee::SetAddress( const std::string& address ) {
	itsAddress = address;
}

void Employee::SetName( const std::string& name ) {
	itsName = name;
}

bool Employee::IsPayDate( const Date& date ) {
	return itsps->IsPayDate(date);
}

void Employee::Payday( PayCheck& paycheck ) {
	double grossPay = itspc->CalculatePay(paycheck);

	double deductions = 0.0;
	if (itsaf == 0) {
		deductions = 0.0;
	} else {
		deductions = itsaf->CalculateDeductions();
	}	

	double netPay = grossPay - deductions;

	paycheck.SetGrossPay(grossPay);
	paycheck.SetDeductions(deductions);
	paycheck.SetNetPay(netPay);
	paycheck.SetName(itsName);

	itspm->Pay(paycheck);
}

Affiliation * Employee::GetAffilication() const {
	return itsaf;
}

std::string Employee::GetName() const {
	return itsName;
}

std::string Employee::GetAddress() const {
	return itsAddress;
}

int Employee::GetEmpId() const {
	return itsEmpid;
}

PaymentClassification * Employee::GetPaymentClassification() const {
	return itspc;
}

PaymentMethod * Employee::GetPaymentMethod() const {
	return itspm;
}

PaymentSchedule * Employee::GetPaymentSchedule() const {
	return itsps;
}

 