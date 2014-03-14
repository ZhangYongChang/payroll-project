#include "changeemployeetransaction.h"
#include "databaseproxy.h"
#include "proxy.h"
 
ChangeEmployeeTransaction::ChangeEmployeeTransaction( int empid ) 
	: itsEmpid(empid) {
}

ChangeEmployeeTransaction::~ChangeEmployeeTransaction() {
}

void ChangeEmployeeTransaction::Execute() {

	Employee *e = DBPROXY->GetEmployee(itsEmpid);

	if (e != 0) {
		Change(e);
	} else {
		return;
	}
} 