#include "memorypayrolldatabase.h"
#include "factory.h"

DatabaseProxy *MemoryDBFactory::makeDatabase()
{
	IOHelp *io = new IOSupport("outfile.txt", 0);
	return new MemoryPayrollDatabase(io);
}

MemoryDBFactory::~MemoryDBFactory()
{
}

MemoryDBFactory::MemoryDBFactory()
{
}
