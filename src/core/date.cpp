#include "date.h"

#include <sstream> 

Date::Date( const int &year, const int& month, const int &day ) 
	: itsYear(year),
	itsMonth(month),
	itsDay(day){
}

Date::Date( const Date& date ) :
	itsYear(date.itsYear),
	itsMonth(date.itsMonth),
	itsDay(date.itsDay) {
}

Date::~Date() {
}

bool Date::operator==( const Date& other ) {
	return itsYear == other.itsYear && \
		itsMonth == other.itsMonth && \
		itsDay == other.itsDay;
}

Date::Date() : itsYear(0), itsMonth(0), itsDay(0) {
}

Date::Date( const std::string& str ) {
	std::string strDate = str;
	std::string strSub;
	size_t pos = strDate.find('-');
	if ( pos != std::string::npos ) {
		std::stringstream ssm;
		strSub = strDate.substr(0, pos);
		ssm << strSub;
		ssm >> itsYear;
		strDate = strDate.substr(pos + 1, strDate.length() - pos - 1);
	}

	pos = strDate.find('-');
	if ( pos != std::string::npos ) {
		std::stringstream ssm;
		strSub = strDate.substr(0, pos);
		ssm << strSub;
		ssm >> itsMonth;
		strDate = strDate.substr(pos + 1, strDate.length() - pos - 1);
	}

	std::stringstream ssm;
	ssm << strDate;
	ssm >> itsDay;
}

std::string Date::ToString() const {
	std::stringstream ssm;
	ssm << itsYear << '-' << itsMonth << '-' << itsDay;
	return ssm.str();
}

Date& Date::operator=( const Date& date ) {
	itsYear = date.itsYear;
	itsMonth = date.itsMonth;
	itsDay = date.itsDay;
	return *this;
}

std::ostream& operator<<( std::ostream& _out, const Date& _date ) {
	_out << _date.GetYear() << "-";
	_out << _date.GetMonth() <<"-";
	_out << _date.GetDay() << "\t";
	return _out;
}

std::istream& operator>>( std::istream& _in, Date& date ) {
	std::string strDate;
	_in >> strDate;
	Date tempDate(strDate);
	date = tempDate;
	return _in;
} 