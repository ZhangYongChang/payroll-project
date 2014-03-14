#include "mailmethod.h"

#include "paycheck.h"

// #include <iostream> 

MailMethod::MailMethod() {
}

MailMethod::~MailMethod() {
}

void MailMethod::Pay( PayCheck &pc )
{
	pc.GetName();
	/******************************************************
	std::cout << "name: " << pc.GetName() << '\n' 
		<< "gross: " << pc.GetGrossPay() << '\n'
		<< "deductions: " << pc.GetDeductions() << '\n'
		<< "net: " << pc.GetNetPay() << std::endl;
	*******************************************************/
}