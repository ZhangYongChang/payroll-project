#include "changeclassificationtransaction.h"

#include "employee.h"

ChangeClassificationTransaction::ChangeClassificationTransaction(int empid)
	: ChangeEmployeeTransaction(empid) {
}

ChangeClassificationTransaction::~ChangeClassificationTransaction() {
}

void ChangeClassificationTransaction::Change(Employee *e) {
	e->SetPaymentClassification(GetPaymentClassification());
	e->SetPaymentSchedule(GetPaymentSchedule());
}