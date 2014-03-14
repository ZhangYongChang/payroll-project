#ifndef MAILMETHOD_H_
#define MAILMETHOD_H_

#include "methods.h"
#include "paymentmethod.h" 

class METHODAPI MailMethod :
	public PaymentMethod
{
public:
	MailMethod();
	virtual ~MailMethod();

	virtual void Pay( PayCheck &pc );
};

#endif