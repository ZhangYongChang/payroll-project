#include "hourlyclassification.h"

#include "paycheck.h"

HourlyClassification::HourlyClassification( double hourly )
	: itsHourly(hourly) {
		itsTimeCards = new std::vector<TimeCard>();
}

HourlyClassification::~HourlyClassification() {
	delete itsTimeCards;
}

void HourlyClassification::AddTimeCard( const TimeCard& timecard ) {
	itsTimeCards->push_back(timecard);
}

TimeCard HourlyClassification::GetTimeCard( const Date& date ) {
	for (std::vector<TimeCard>::iterator it = itsTimeCards->begin();
		it != itsTimeCards->end();
		++it) {
			if (it->GetDate() == date) {
				return *it;
			}
	}
	
	TimeCard tc(date, 0);
	return tc;
}

double HourlyClassification::CalculatePay( PayCheck &pc )
{
    double dfGrossPay = 0.0;

    for (TimeCardList::iterator it = itsTimeCards->begin();
        it != itsTimeCards->end();
        ++it)
    {
        dfGrossPay = dfGrossPay + it->GetHours() * itsHourly;
    }

	pc.SetGrossPay(dfGrossPay);

	return dfGrossPay;
}