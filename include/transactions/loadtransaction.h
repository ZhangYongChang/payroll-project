#ifndef PAYROLL_LOADTRANSACTION_H_
#define PAYROLL_LOADTRANSACTION_H_

#include "transactions.h"
#include "transaction.h"

#include <string> 

class TRANSACTIONSAPI LoadTransaction :
	public Transaction {
public:
	LoadTransaction(const std::string& filename);
public:
	virtual ~LoadTransaction();
	virtual void Execute();
	
private:
	std::string itsFileName;
}; 

#endif