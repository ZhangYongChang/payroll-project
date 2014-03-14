#include "addcommisionemployee.h"

#include "commisionclassification.h"
#include "biweeklyschedule.h"
#include "mailmethod.h"

AddCommisionEmployee::AddCommisionEmployee( 
	const int empid, 
	const std::string &name, 
	const std::string &address, 
	const double salaried, 
	const double rate )
	: AddEmployeeTransaction(empid, name, address),
	itsBasicSalaried(salaried),
	itsRate(rate) {
}

AddCommisionEmployee::~AddCommisionEmployee() {
}

PaymentMethod *AddCommisionEmployee::GetPayMethod() const {
	return new MailMethod();
}

PaymentClassification *AddCommisionEmployee::GetClassification() const {
	return new CommisionClassification(itsBasicSalaried, itsRate);
}

PaymentSchedule *AddCommisionEmployee::GetSchedule() const {
	return new BiweeklySchedule();
}