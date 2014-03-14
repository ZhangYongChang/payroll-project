#include "deleteemployeetransaction.h"
#include "databaseproxy.h"
#include "proxy.h"

DeleteEmployeeTransaction::DeleteEmployeeTransaction( const int empid )
	: itsEmpid(empid) {
}

DeleteEmployeeTransaction::~DeleteEmployeeTransaction() {
}

void DeleteEmployeeTransaction::Execute() {
	DBPROXY->DeleteEmployee(itsEmpid);
}