#ifndef TRANSACTIONS_DATABASE_PROXY_H_
#define TRANSACTIONS_DATABASE_PROXY_H_

#include "transactions.h"
#include "databaseproxy.h"

class TRANSACTIONSAPI DBInstance
{
public:
	DBInstance();
	~DBInstance();
	static DatabaseProxy *getInstance();

private:
	static DatabaseProxy *_instance;
};

TRANSACTIONSAPI DatabaseProxy *getInstance();

#define DBPROXY DBInstance::getInstance()

#endif