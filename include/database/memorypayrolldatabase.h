#ifndef MEMORYPAYROLLDATABASE_H_
#define MEMORYPAYROLLDATABASE_H_

#include "databaseproxy.h"

#include <map>
#include <list>
#include <fstream>

class Employee;

class IOSupport :
	public IOHelp
{
public:
	IOSupport( const std::string &name, int type );
	virtual ~IOSupport();
	virtual Employee * Read();
	virtual void Write( Employee *e );

protected:
	std::ifstream _in;
	std::ofstream _out;
};

class MemoryPayrollDatabase :
	public DatabaseProxy {
public:
	MemoryPayrollDatabase(IOHelp *io);
	virtual ~MemoryPayrollDatabase();

	bool Load(const std::string& filepath);
	bool Save(const std::string& filepath);

	Employee *GetEmployee(int empid);
	void AddEmployee(int empid, Employee * employee);

	void AddUnionMember(int memberId, Employee *employee);
	Employee *GetUnionMember(int memberId);

	void DeleteEmployee(int empid);
	

	void GetAllEmployeeIds(std::list<int> &empIds);
	virtual void ClearEmployees();
	virtual bool Serialize();
	virtual bool DeSerialize();

private:
	bool InnerDeleteAffilicationMember(Employee *e);

private:
	typedef int EmpID;
	typedef int MemberID;
	typedef std::map<EmpID, Employee *> EmployeeTable;

	std::map<EmpID, Employee *> itsEmplyees;
	std::map<MemberID, Employee *> itsAffilications;
};

#endif