#include "addsalariedemployee.h"

#include "salariedclassification.h"
#include "monthschedule.h"
#include "mailmethod.h"
 
AddSalariedEmployee::AddSalariedEmployee( int empid, 
	const std::string &name, 
	const std::string &address, 
	double salary)
	: AddEmployeeTransaction(empid, name, address), 
	itsSalary(salary) {
}

AddSalariedEmployee::~AddSalariedEmployee() {
}

PaymentMethod *AddSalariedEmployee::GetPayMethod() const {
	PaymentMethod *pm = new MailMethod();
	return pm;
}

PaymentClassification *AddSalariedEmployee::GetClassification() const {
	PaymentClassification *pc = new SalariedClassification(itsSalary);
	return pc;
}

PaymentSchedule *AddSalariedEmployee::GetSchedule() const {
	PaymentSchedule *ps = new MonthlySchedule();
	return ps;
} 