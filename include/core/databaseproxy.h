#ifndef PAYROLLDATABASE_H_
#define PAYROLLDATABASE_H_

#include "core.h"

#include <string>
#include <list>

class Employee;

class COREAPI IOHelp
{
public:
	IOHelp( const std::string &name, int type );
	virtual ~IOHelp();

	virtual Employee *Read() = 0;
	virtual void Write(Employee *e) = 0;

public:
	std::string _name;
	int _type;
};

class COREAPI DatabaseProxy
{
public:
	DatabaseProxy(IOHelp *_io = 0);
	virtual ~DatabaseProxy();

	virtual Employee *GetEmployee(int empid) = 0;
	virtual void AddEmployee(int empid, Employee * employee) = 0;
	virtual void DeleteEmployee(int empid) = 0;

	virtual void GetAllEmployeeIds(std::list<int> &empIds) = 0;
	virtual void ClearEmployees() = 0;

	virtual void AddUnionMember(int memberId, Employee *employee) = 0;
	virtual Employee *GetUnionMember(int memberId) = 0;

	virtual bool Serialize() = 0;
	virtual bool DeSerialize() = 0;

protected:
	IOHelp *io;
};

class COREAPI DBFactory
{
public:
	DBFactory();
	virtual ~DBFactory();
	virtual DatabaseProxy *makeDatabase() = 0;

protected:
	DatabaseProxy *_instance;
};

#endif