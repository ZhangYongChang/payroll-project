#include "salesreceipt.h" 

SalesReceipt::~SalesReceipt() {
}

SalesReceipt::SalesReceipt( const SalesReceipt& receipt )
	: itsDate(receipt.itsDate),
	itsAmount(receipt.itsAmount) {
}

SalesReceipt::SalesReceipt( const Date& date, const double& amount )
	: itsDate(date),
	itsAmount(amount) {
}