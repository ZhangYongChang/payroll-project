#ifndef FACTORY_H_
#define FACTORY_H_

#include "databases.h"
#include "databaseproxy.h"

class DATABASEAPI MemoryDBFactory :
	public DBFactory
{
public:
	MemoryDBFactory();
	virtual ~MemoryDBFactory();
	virtual DatabaseProxy * makeDatabase();
};

#endif