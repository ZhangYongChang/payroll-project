#include "salariedclassification.h"

#include "paycheck.h"
 
SalariedClassification::SalariedClassification( double salaried )
	: itsSalaried(salaried) {
}

SalariedClassification::~SalariedClassification() {
}

double SalariedClassification::CalculatePay( PayCheck &pc )
{
	pc.SetGrossPay(itsSalaried);

	return itsSalaried;
}
