#include "changenametransaction.h"

#include "employee.h"

ChangeNameTransaction::ChangeNameTransaction( int empid, std::string name ) 
    : ChangeEmployeeTransaction(empid),
	itsName(name) {
}

ChangeNameTransaction::~ChangeNameTransaction() {
}

void ChangeNameTransaction::Change(Employee *e) {
	e->SetName(itsName);
}