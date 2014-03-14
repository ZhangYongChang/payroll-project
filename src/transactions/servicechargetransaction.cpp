#include "servicechargetransaction.h"
#include "proxy.h"
#include "unionaffiliation.h"
#include "employee.h"
#include "databaseproxy.h"

ServiceChargeTransaction::ServiceChargeTransaction( const int& memberId, 
													const Date& date, 
													const double& amount) 
	: itsMemberId(memberId),
	itsDate(date),
	itsAmount(amount) {
}

ServiceChargeTransaction::~ServiceChargeTransaction() {
}

void ServiceChargeTransaction::Execute() {
	Employee *e = DBPROXY->GetUnionMember(itsMemberId);
	Affiliation *af = e->GetAffilication();
	if (af == 0) {
		return;
	} else {
		UnionAffiliation* ua = dynamic_cast<UnionAffiliation*>(af);
		if (ua == 0) {
			return;
		} else {
			ServiceCharge charge(itsDate, itsAmount);
			ua->AddSericeCharge(charge);
		}
	}

} 