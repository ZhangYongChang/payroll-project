#ifndef PAYROLL_SAVETRANSACTION_H_
#define PAYROLL_SAVETRANSACTION_H_

#include "transactions.h"
#include "transaction.h"

#include <string> 

class TRANSACTIONSAPI SaveTransaction :
	public Transaction {
public:
	SaveTransaction(const std::string& filename);
public:
	virtual ~SaveTransaction();
	virtual void Execute();

private:
	std::string itsFileName;
};

#endif