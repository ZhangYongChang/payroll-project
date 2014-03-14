#include "databaseproxy.h"

DatabaseProxy::DatabaseProxy( IOHelp *_io /*= 0*/ )
	: io(_io)
{

}

DatabaseProxy::~DatabaseProxy()
{
}

IOHelp::IOHelp( const std::string &name, int type )
	: _name(name), _type(type)
{
}

IOHelp::~IOHelp()
{

}

DBFactory::DBFactory()
: _instance(0)
{
}

DBFactory::~DBFactory()
{
}
