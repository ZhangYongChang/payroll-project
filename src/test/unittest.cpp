#include <gtest/gtest.h>

#include "proxy.h"
#include "databaseproxy.h"

#include "employee.h"
#include "addsalariedemployee.h"
#include "salariedclassification.h"
#include "addhourlyemployee.h"
#include "hourlyclassification.h"
#include "monthschedule.h"
#include "addcommisionemployee.h"
#include "commisionclassification.h"
#include "deleteemployeetransaction.h"
#include "timecardtransaction.h"
#include "salesreceipttransaction.h"
#include "servicechargetransaction.h"
#include "unionaffiliation.h"
#include "servicecharge.h"
#include "changenametransaction.h"
#include "changeaddresstransaction.h"
#include "changehourlytransaction.h"
#include "changesalariedtransaction.h"
#include "savetransaction.h"
#include "loadtransaction.h"
#include "paydaytransaction.h"
#include "paycheck.h"



TEST(AddSalariedEmployeeTest, PayrollTest) {

	AddSalariedEmployee st(1, "Bob", "Beijing", 1000.00);
	st.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(1);
	EXPECT_TRUE(e->GetName() == "Bob");
	EXPECT_TRUE(e->GetAddress() == "Beijing");
	EXPECT_TRUE(e->GetEmpId() == 1);

	PaymentClassification * pc = e->GetPaymentClassification();
	SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
	EXPECT_TRUE(sc != 0);
	EXPECT_TRUE(sc->GetSalary() == 1000.00);
}

TEST(AddHourlyEmployeeTest, PayrollTest) {

	AddHourlyEmployee ht(2, "Test", "Shanghai", 50.00);
	ht.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(2);
	EXPECT_TRUE(e->GetName() == "Test");
	EXPECT_TRUE(e->GetAddress() == "Shanghai");
	EXPECT_TRUE(e->GetEmpId() == 2);

	PaymentClassification * pc = e->GetPaymentClassification();
	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	EXPECT_TRUE(hc != 0);
	EXPECT_TRUE(hc->GetHourlySalaried() == 50.00);
}

TEST(AddCommisionEmployeeTest, PayrollTest) {

	AddCommisionEmployee ct(3, "Test", "Shanghai", 1500.00, 0.5);
	ct.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(3);
	EXPECT_TRUE(e->GetName() == "Test");
	EXPECT_TRUE(e->GetAddress() == "Shanghai");
	EXPECT_TRUE(e->GetEmpId() == 3);

	PaymentClassification * pc = e->GetPaymentClassification();
	CommisionClassification* hc = dynamic_cast<CommisionClassification*>(pc);
	EXPECT_TRUE(hc != 0);
	EXPECT_TRUE(hc->GetSalaried() == 1500.00);
	EXPECT_TRUE(hc->GetRate() == 0.5);
}

TEST(DeleteEmployeeTest, PayrollTest) {

	AddCommisionEmployee ace(4, "Test4", "Shanghai", 1600.00, 0.3);
	ace.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(4);
	EXPECT_TRUE(e->GetName() == "Test4");
	EXPECT_TRUE(e->GetAddress() == "Shanghai");
	EXPECT_TRUE(e->GetEmpId() == 4);

	DeleteEmployeeTransaction t(4);
	t.Execute();

	e = ((DatabaseProxy *)getInstance())->GetEmployee(4);
	EXPECT_TRUE(e == 0);
}

TEST(TimeCardTransactionTest, PayrollTest) {

	AddHourlyEmployee ahe(5, "Test5", "Shanghai", 100.00);
	ahe.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(5);
	EXPECT_TRUE(e->GetName() == "Test5");
	EXPECT_TRUE(e->GetAddress() == "Shanghai");
	EXPECT_TRUE(e->GetEmpId() == 5);

	Date date(2010, 10, 10);

	TimeCardTransaction tct(5, date, 10);
	tct.Execute();

	e = ((DatabaseProxy *)getInstance())->GetEmployee(5);
	PaymentClassification* pc = e->GetPaymentClassification();
	EXPECT_TRUE(pc != 0);

	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	EXPECT_TRUE(hc != 0);

	TimeCard timecard(hc->GetTimeCard(date));
	EXPECT_TRUE(timecard.GetHours() == 10);	
}

TEST(SalesReceiptTransactionTest, PayrollTest) {
	
	int empid = 6;
	Date date(2012, 10, 10);
	double amount = 1000.00;

	AddCommisionEmployee ace(empid, "Test6", "Home6", 1000.00, 0.5);
	ace.Execute();

	SalesReceiptTransaction srt(6, date, amount);
	srt.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	PaymentClassification* pc = e->GetPaymentClassification();
	EXPECT_TRUE(pc != 0);

	CommisionClassification* cc = dynamic_cast<CommisionClassification*>(pc);
	EXPECT_TRUE(cc != 0);

	SalesReceipt receipt(cc->GetSalesReceipt(date));
	EXPECT_TRUE(receipt.GetAmount() == amount);
}

TEST(ServiceChargeTransactionTest, PayrollTest) {
	int empid = 7;
	AddHourlyEmployee ahe(empid, "Test7", "Home7", 50.00);
	ahe.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	EXPECT_TRUE(e != 0);
	Affiliation * af(new UnionAffiliation());
	e->SetAffilication(af);

	int memberId = 86;
	((DatabaseProxy *)getInstance())->AddUnionMember(memberId, e);

	Date date(2005, 8, 8);
	ServiceChargeTransaction sct(memberId, date, 12.95);
	sct.Execute();

	e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	UnionAffiliation* uf = 
		dynamic_cast<UnionAffiliation*>(e->GetAffilication());
	EXPECT_TRUE(uf != 0);

	ServiceCharge sc = uf->GetServiceCharge(date);
	EXPECT_TRUE(sc.GetAmount() == 12.95);
}

TEST(ChangeNameTransactionTest, PayrollTest) {

	int empid = 8;
	AddHourlyEmployee ahe(empid, "Test8", "Home8", 50.00);
	ahe.Execute();

	ChangeNameTransaction ant(empid, "Test88");
	ant.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	EXPECT_TRUE(e != 0);
	EXPECT_TRUE(e->GetName() == "Test88");
}

TEST(ChangeAddressTransactionTest, PayrollTest) {
	int empid = 9;
	AddHourlyEmployee ahe(empid, "Test9", "Home9", 50.00);
	ahe.Execute();

	ChangeAddressTransaction cat(empid, "Home99");
	cat.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	EXPECT_TRUE(e != 0);
	EXPECT_TRUE(e->GetAddress() == "Home99");
}

TEST(ChangeHourlyTransactionTest, PayrollTest) {
	int empid = 10;
	AddSalariedEmployee st(empid, "Test10", "Home10", 1000.00);
	st.Execute();

	ChangeHourlyTransaction cht(empid, 50.00);
	cht.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	EXPECT_TRUE(e != 0);

	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(e->GetPaymentClassification());
	EXPECT_TRUE(hc != 0);
}

TEST(ChangeSalariedTransactionTest, PayrollTest) {
	int empid = 10;
	AddHourlyEmployee ht(empid, "Test11", "Home10", 50.00);
	ht.Execute();

	ChangeSalariedTransaction cst(empid, 1000.00);
	cst.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
	EXPECT_TRUE(e != 0);

	SalariedClassification* ms = dynamic_cast<SalariedClassification*>(e->GetPaymentClassification());
	EXPECT_TRUE(ms != 0);

	EXPECT_TRUE(ms->GetSalary() == 1000.00);
}

TEST(SaveTransactionTest, PayrollTest) {
	SaveTransaction st("D:\\data.txt");
	st.Execute();
}

TEST(LoadTransactionTest, PayrollTest) {
	LoadTransaction lt("D:\\data.txt");
	lt.Execute();

	Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(1);
	EXPECT_TRUE(e != 0);
}

TEST(PaydayTransactionForSalariedEmployeeTest, PayrollTest) {
	((DatabaseProxy *)getInstance())->ClearEmployees();

	int empid = 100;

	AddSalariedEmployee ase(empid, "name01", "home01", 1000.00);
	ase.Execute();

	Date paydate(2011, 2, 15);

	PaydayTransaction pt(paydate);
	pt.Execute();
	PayCheck *pc = pt.GetPayCheck(empid);

	EXPECT_TRUE(pc->GetName() == "name01");
	EXPECT_TRUE(pc->GetGrossPay() == 1000.00);
	EXPECT_TRUE(pc->GetDeductions() == 0.0);
	EXPECT_TRUE(pc->GetNetPay() == 1000.00);
}

TEST(PaydayTransactionForCommisionedEmployeeTest, PayrollTest) {
    ((DatabaseProxy *)getInstance())->ClearEmployees();

    int empid = 101;
    Date date(2012, 10, 10);
    double amount = 1000.00;

    AddCommisionEmployee ace(empid, "name02", "Home6", 1000.00, 0.5);
    ace.Execute();

    SalesReceiptTransaction srt(empid, date, amount);
    srt.Execute();

    Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
    PaymentClassification* pc = e->GetPaymentClassification();
    EXPECT_TRUE(pc != 0);

    CommisionClassification* cc = dynamic_cast<CommisionClassification*>(pc);
    EXPECT_TRUE(cc != 0);

    SalesReceipt receipt(cc->GetSalesReceipt(date));
    EXPECT_TRUE(receipt.GetAmount() == amount);

    Date paydate(2011, 2, 14);

    PaydayTransaction pt(paydate);
    pt.Execute();
    PayCheck *check = pt.GetPayCheck(empid);

    EXPECT_TRUE(check->GetName() == "name02");
    EXPECT_EQ(check->GetGrossPay(), 1500.00);
    EXPECT_EQ(check->GetDeductions(), 0.0);
    EXPECT_EQ(check->GetNetPay(), 1500.00);
}

TEST(PaydayTransactionForHourlyEmployeeTest, PayrollTest) {
    ((DatabaseProxy *)getInstance())->ClearEmployees();    

    int empid = 102;
    AddHourlyEmployee ahe(empid, "name02", "Shanghai", 20.00);
    ahe.Execute();

    Employee *e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
    EXPECT_TRUE(e->GetName() == "name02");
    EXPECT_TRUE(e->GetAddress() == "Shanghai");
    EXPECT_TRUE(e->GetEmpId() == empid);

    Date date(2012, 2, 5);

    TimeCardTransaction tct(empid, date, 10);
    tct.Execute();

    e = ((DatabaseProxy *)getInstance())->GetEmployee(empid);
    PaymentClassification* pc = e->GetPaymentClassification();
    EXPECT_TRUE(pc != 0);

    HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
    EXPECT_TRUE(hc != 0);

    TimeCard timecard(hc->GetTimeCard(date));
    EXPECT_TRUE(timecard.GetHours() == 10);	
    
    Date paydate(2011, 2, 7);

    PaydayTransaction pt(paydate);
    pt.Execute();
    PayCheck *check = pt.GetPayCheck(empid);

    EXPECT_TRUE(check != NULL);

    EXPECT_TRUE(check->GetName() == "name02");
    EXPECT_EQ(check->GetGrossPay(), 200.00);
    EXPECT_EQ(check->GetDeductions(), 0.0);
    EXPECT_EQ(check->GetNetPay(), 200.00);
}