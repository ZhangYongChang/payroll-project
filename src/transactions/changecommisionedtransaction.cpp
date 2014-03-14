#include "changecommisionedtransaction.h"
#include "biweeklyschedule.h"
#include "commisionclassification.h"

ChangeCommisionedTransaction::~ChangeCommisionedTransaction() {
}

ChangeCommisionedTransaction::ChangeCommisionedTransaction( const int empid, 
																	const double& salaried, 
																	const double& rate )
																	: ChangeClassificationTransaction(empid),
																	itsSalaried(salaried),
																	itsRate(rate) {
}

PaymentClassification *ChangeCommisionedTransaction::GetPaymentClassification() const {
	PaymentClassification *pc = new CommisionClassification(itsSalaried, itsRate);
	return pc;

}

PaymentSchedule *ChangeCommisionedTransaction::GetPaymentSchedule() const {
	PaymentSchedule *ps = new BiweeklySchedule();
	return ps;
}
