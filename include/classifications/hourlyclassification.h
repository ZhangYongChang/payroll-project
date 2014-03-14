#ifndef PAYROLL_HOURLYCLASSIFICATION_H_
#define PAYROLL_HOURLYCLASSIFICATION_H_

#include "paymentclassification.h"
#include "classifications.h"
#include "timecard.h"

#include <vector> 

class CLASSIFICATIONSAPI HourlyClassification :
	public PaymentClassification
{
public:
	HourlyClassification(double hourly);
	virtual ~HourlyClassification();

	double GetHourlySalaried() const { return itsHourly; }
	void AddTimeCard( const TimeCard& timecard );
	std::vector<TimeCard> GetTimeCards() const { return *itsTimeCards; }
	TimeCard GetTimeCard(const Date& date);

	virtual double CalculatePay( PayCheck &pc );

private:
	typedef std::vector<TimeCard> TimeCardList;

	double itsHourly;
	std::vector<TimeCard> *itsTimeCards;
}; 

#endif