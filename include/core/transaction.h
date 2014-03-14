#ifndef PAYROLL_TRANSACTION_H_
#define PAYROLL_TRANSACTION_H_

#include "core.h"

class COREAPI Transaction {
public:
	Transaction();
	virtual ~Transaction();

	virtual void Execute() = 0;
}; 

#endif