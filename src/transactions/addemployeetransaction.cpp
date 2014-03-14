#include "addemployeetransaction.h"
#include "employee.h"
#include "databaseproxy.h"
#include "proxy.h"

AddEmployeeTransaction::AddEmployeeTransaction( int empid, 
											   const std::string &name, 
											   const std::string &address )
	: itsEmpid(empid), itsName(name), itsAddress(address) {
}

AddEmployeeTransaction::~AddEmployeeTransaction() {
}

void AddEmployeeTransaction::Execute() {
	PaymentClassification *pc = GetClassification();
	PaymentSchedule *ps = GetSchedule();
	PaymentMethod *pm = GetPayMethod();

	Employee *e = new Employee(itsEmpid, itsName, itsAddress);
	e->SetPaymentClassification(pc);
	e->SetPaymentSchedule(ps);
	e->SetPaymentMethod(pm);

	DBPROXY->AddEmployee(itsEmpid, e);	
} 