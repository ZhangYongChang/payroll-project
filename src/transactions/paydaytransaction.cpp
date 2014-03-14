#include "paydaytransaction.h"

#include <list>

#include "paycheck.h"
#include "employee.h"
#include "databaseproxy.h"
#include "proxy.h"

void PaydayTransaction::Execute()
{
	std::list<int> empIds;
	DBPROXY->GetAllEmployeeIds(empIds);

	for (std::list<int>::iterator it = empIds.begin();
		it != empIds.end();
		++it)
	{
		int empid = *it;

		Employee *e = DBPROXY->GetEmployee(empid);
		if (e != NULL)
		{
			if (e->IsPayDate(paydate))
			{
				PayCheck *pc = new PayCheck(paydate);
				pc->SetName(e->GetName());
				itsPaychecks[empid] = pc;
				e->Payday(*pc);
			}
		}
	}
	
}

PaydayTransaction::PaydayTransaction( Date &date )
: paydate(date)
{
}

PaydayTransaction::~PaydayTransaction()
{

	for (std::map<int, PayCheck *>::iterator it = itsPaychecks.begin();
		it != itsPaychecks.end();
		++it)
	{
		delete it->second;
	}
}

PayCheck * PaydayTransaction::GetPayCheck( int empid )
{
    return itsPaychecks[empid];
}

 