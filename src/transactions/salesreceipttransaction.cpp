#include "salesreceipttransaction.h"
#include "employee.h"
#include "commisionclassification.h"
#include "databaseproxy.h"
#include "proxy.h"

SalesReceiptTransaction::SalesReceiptTransaction( const int& empid, 
												 const Date& date, 
												 const double& amount )
	: itsEmpid(empid),
	itsDate(date),
	itsAmount(amount) {
}

SalesReceiptTransaction::~SalesReceiptTransaction() {
}

void SalesReceiptTransaction::Execute() {
	Employee *e = DBPROXY->GetEmployee(itsEmpid);
	if (e == 0) {
		return;
	} else {
		PaymentClassification * pc = e->GetPaymentClassification();
		CommisionClassification* cc = dynamic_cast<CommisionClassification*>(pc);

		if (cc == 0) {
			return;
		} else {
			SalesReceipt receipt(itsDate, itsAmount);
			cc->AddSalesReceipt(receipt);
		}
	}

} 