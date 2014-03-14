#ifndef PAYROLL_EMPLOYEE_H_
#define PAYROLL_EMPLOYEE_H_

#include "core.h"

#include <string>

class PaymentClassification;
class PaymentSchedule;
class PaymentMethod;
class Affiliation;
class Date;
class PayCheck; 

class COREAPI Employee {
public:
	Employee( const int empid, 
        const std::string &name, 
        const std::string &address );

	~Employee();

	std::string GetName() const;
	std::string GetAddress() const;
	int GetEmpId() const;

	void SetName( const std::string& name );
	void SetAddress(const std::string& address);	

	void SetPaymentClassification( PaymentClassification * pc );
	void SetPaymentSchedule( PaymentSchedule * ps );
	void SetPaymentMethod( PaymentMethod * pm );

	PaymentClassification *GetPaymentClassification() const;	
	PaymentSchedule *GetPaymentSchedule() const;
	PaymentMethod *GetPaymentMethod() const;

	void SetAffilication( Affiliation * af );
	Affiliation *GetAffilication() const;

	bool IsPayDate(const Date& date);
	void Payday(PayCheck& paycheck);

private:
	int							itsEmpid;
	std::string					itsName;
	std::string					itsAddress;

	PaymentClassification *		itspc;
	PaymentSchedule *			itsps;
	PaymentMethod *				itspm;
	Affiliation *				itsaf;
};

#endif

