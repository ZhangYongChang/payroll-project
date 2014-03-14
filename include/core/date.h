#ifndef PAYROLL_DATE_H
#define PAYROLL_DATE_H

#include "core.h"

#include <ostream>
#include <istream>

class Date;

COREAPI std::ostream& operator << (std::ostream& _out, const Date& date);
COREAPI std::istream& operator >> (std::istream& _in, Date& date);

class COREAPI Date 
{
	friend COREAPI std::ostream& operator << (std::ostream& _out, const Date& date);
	friend COREAPI std::istream& operator >> (std::istream& _in, Date& date);

public:
	Date();
	Date( const std::string& strDate );
	Date( const int &year, const int& month, const int &day );
	Date( const Date& date );
	Date& operator = ( const Date& date );

	bool operator ==(const Date& other);
public:
	virtual ~Date();

	int GetYear() const { return itsYear; }
	int GetMonth() const { return itsMonth; }
	int GetDay() const { return itsDay; }
	std::string ToString() const;

private:
	int itsYear;
	int itsMonth;
	int itsDay;
};

#endif