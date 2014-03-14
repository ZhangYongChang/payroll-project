#include "changeaddresstransaction.h"

#include "employee.h"

ChangeAddressTransaction::ChangeAddressTransaction( int empid, 
                                                   const std::string& address )
	: ChangeEmployeeTransaction(empid),
	itsAddress(address) {
}

ChangeAddressTransaction::~ChangeAddressTransaction() {
}

void ChangeAddressTransaction::Change(Employee *e) {
	e->SetAddress(itsAddress);
}