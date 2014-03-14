#include "proxy.h"
#include "factory.h"

DatabaseProxy *makeProxy()
{
	MemoryDBFactory factory;
	return factory.makeDatabase();
}

DatabaseProxy * getInstance()
{
	return DBPROXY;
}

DBInstance::~DBInstance()
{
}

DBInstance::DBInstance()
{
}

DatabaseProxy *DBInstance::getInstance()
{
	if (_instance == 0)
	{
		_instance = makeProxy();
	}

	return _instance;
}

DatabaseProxy * DBInstance::_instance = 0;
