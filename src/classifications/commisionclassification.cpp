#include "commisionclassification.h"

#include "paycheck.h"

CommisionClassification::~CommisionClassification() {
	delete itsSalesReceipt;
}

CommisionClassification::CommisionClassification( const double salaried, 
	const double rate ) : 
	itsBasicSalaried(salaried),
	itsRate(rate) {
	itsSalesReceipt = new SalesReceiptList();
}

SalesReceipt CommisionClassification::GetSalesReceipt(const Date& date) {
	for (std::vector<SalesReceipt>::iterator it = itsSalesReceipt->begin();
		it != itsSalesReceipt->end();
		++it) {
			if (it->GetDate() == date) {
				return *it;
			}
	}

	SalesReceipt sr(date, 0.00);
	return sr;
}

void CommisionClassification::AddSalesReceipt( const SalesReceipt& receipt ) {
	itsSalesReceipt->push_back(receipt);
}

double CommisionClassification::CalculatePay( PayCheck &pc )
{
    double dfCommisionSales = 0;

    for (SalesReceiptList::iterator it = itsSalesReceipt->begin();
        it != itsSalesReceipt->end();
        ++it)
    {
        dfCommisionSales = dfCommisionSales + it->GetAmount() * itsRate;
    }

    dfCommisionSales = dfCommisionSales + itsBasicSalaried;

    pc.SetGrossPay(dfCommisionSales);

	return dfCommisionSales;
} 