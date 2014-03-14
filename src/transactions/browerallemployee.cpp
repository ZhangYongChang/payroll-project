#include "browerallemployee.h"
#include <list>
#include "proxy.h"

CBrowerAllEmployee::CBrowerAllEmployee() {
}

CBrowerAllEmployee::~CBrowerAllEmployee() {
}

void CBrowerAllEmployee::Execute() {
	std::list<int> empIds;
	DBPROXY->GetAllEmployeeIds(empIds);
	itsEmployees.clear();

	for (std::list<int>::iterator it = empIds.begin();
		it != empIds.end();
		++it)
	{
		itsEmployees[*it] = DBPROXY->GetEmployee(*it);
	}
}