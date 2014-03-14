#include "memorypayrolldatabase.h"

#include "employee.h"

#include "salariedclassification.h"
#include "hourlyclassification.h"
#include "commisionclassification.h"

#include "biweeklyschedule.h"
#include "weeklyschedule.h"
#include "monthschedule.h"

#include "mailmethod.h"

MemoryPayrollDatabase::~MemoryPayrollDatabase() {
	Employee *e = 0;
	for ( EmployeeTable::iterator it = itsEmplyees.begin();
		it != itsEmplyees.end();
		++it) {
		e = it->second;
		delete e;
	}
}

Employee *MemoryPayrollDatabase::GetEmployee( int empid ) {
	for ( std::map<EmpID, Employee *>::iterator it = itsEmplyees.begin();
		it != itsEmplyees.end();
		++it ) {
			if ( it->first == empid ) {
				return it->second;
			}
	}
	return 0;
}

void MemoryPayrollDatabase::AddEmployee( int empid, Employee *employee ) {
	itsEmplyees[empid] = employee;
}

void MemoryPayrollDatabase::DeleteEmployee( int empid ) {
	Employee *e = itsEmplyees[empid];
	while (InnerDeleteAffilicationMember(e)) {
		continue;
	}
	itsEmplyees.erase(empid);
	delete e;
}

bool MemoryPayrollDatabase::InnerDeleteAffilicationMember( Employee *e ) {
	for (std::map<MemberID, Employee *>::iterator it = itsAffilications.begin();
		it != itsAffilications.end();
		++it) {
			if (it->second == e ) {
				itsAffilications.erase(it);
				return true;
			}
	}

	return false;
}

Employee *MemoryPayrollDatabase::GetUnionMember( int memberId ) {
	return itsAffilications[memberId];
}

void MemoryPayrollDatabase::AddUnionMember( int memberId, Employee *employee ) {
	itsAffilications[memberId] = employee;

}

bool MemoryPayrollDatabase::Load( const std::string& filepath ) {
	ClearEmployees();
	return DeSerialize();
}

bool MemoryPayrollDatabase::Save( const std::string& filepath ) {
	return Serialize();
}

void MemoryPayrollDatabase::GetAllEmployeeIds( std::list<int> &empIds )
{
	for (EmployeeTable::iterator it = itsEmplyees.begin();
		it != itsEmplyees.end();
		++it)
	{
		empIds.push_back(it->first);
	}
}

void MemoryPayrollDatabase::ClearEmployees()
{
	itsEmplyees.clear();
	itsAffilications.clear();
}

bool MemoryPayrollDatabase::Serialize()
{
	for ( std::map<EmpID,Employee *>::iterator it = itsEmplyees.begin();
		it != itsEmplyees.end();
		++it ) {
			io->Write(it->second);
	}

	return true;
}

bool MemoryPayrollDatabase::DeSerialize()
{
	ClearEmployees();
	Employee *e = io->Read();

	while(e != 0)
	{
		itsEmplyees.insert( std::make_pair(e->GetEmpId(), e));
		e = io->Read();
	}

	return true;
}

MemoryPayrollDatabase::MemoryPayrollDatabase( IOHelp *io )
: DatabaseProxy(io)
{
}

Employee * IOSupport::Read()
{
	if (!_in.is_open())
	{
		_in.open(this->_name.c_str());
	}

	int empid;
	_in >> empid;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }

	std::string name;
	_in >> name;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }

	std::string address;
	_in >> address;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }


	Employee *e = new Employee(empid, name, address);

	std::string classification;
	_in >> classification;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }

	// input the employee classification
	if ( classification == "SalariedClassification" ){
		double salary;
		_in >> salary;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }

		PaymentClassification * pc(new SalariedClassification(salary));
		e->SetPaymentClassification(pc);

	} else if ( classification == "HourlyClassification" ) {
		double hourly;
		_in >> hourly;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }

		HourlyClassification* hc = new HourlyClassification(hourly);

		int count;
		_in >> count;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }

		for ( int n = 0; n < count; ++n ) {
			Date date;
			int hours;

			_in >> date;
			if (_in.eof()) { Employee *nulle = 0; return nulle; }
			_in >> hours;
			if (_in.eof()) { Employee *nulle = 0; return nulle; }

			TimeCard timecard(date, hours);
			hc->AddTimeCard(timecard);
		}

		PaymentClassification * pc(hc);
		e->SetPaymentClassification(pc);

	} else if ( classification == "CommisionClassification" ) {
		double basicsalary;
		double rate;
		_in >> basicsalary;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }
		_in >> rate;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }
		CommisionClassification* cc = new CommisionClassification(basicsalary, rate);

		int count;
		_in >> count;
		if (_in.eof()) { Employee *nulle = 0; return nulle; }

		for ( int n = 0; n < count; ++n ) {
			Date date;
			double amount;
			_in >> date;
			if (_in.eof()) { Employee *nulle = 0; return nulle; }
			_in >> amount;
			if (_in.eof()) { Employee *nulle = 0; return nulle; }
			SalesReceipt receipt(date, amount);
			cc->AddSalesReceipt(receipt);			
		}		

		PaymentClassification * pc(cc);
		e->SetPaymentClassification(pc);
	}

	// input the employee payment schedule
	std::string schedule;
	_in >> schedule;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }

	if (schedule == "BiweeklySchedule") {
		PaymentSchedule * ps(new BiweeklySchedule());
		e->SetPaymentSchedule(ps);
	} else if (schedule == "MonthlySchedule") {
		PaymentSchedule * ps(new MonthlySchedule());
		e->SetPaymentSchedule(ps);
	} else if (schedule == "WeeklySchedule") {
		PaymentSchedule * ps(new WeeklySchedule());
		e->SetPaymentSchedule(ps);
	} else { }

	// input the employee payment method
	std::string method;
	_in >> method;
	if (_in.eof()) { Employee *nulle = 0; return nulle; }

	if (method == "MailMethod") {
		PaymentMethod * pm(new MailMethod());
		e->SetPaymentMethod(pm);
	} else { }
	return e;
}

void IOSupport::Write( Employee *e )
{	
	if (!_out.is_open())
	{
		_out.open(this->_name.c_str());
	}

	// output the employee basic information
	_out << e->GetEmpId() << "\t" \
		<< e->GetName() << "\t" \
		<< e->GetAddress() \
		<< std::endl;

	// output the employee classification
	PaymentClassification * pc = e->GetPaymentClassification();

	if ( dynamic_cast<SalariedClassification*>(pc) != 0 ) {
		// SalariedClassification
		SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
		_out << "SalariedClassification" << std::endl;
		_out << sc->GetSalary() << std::endl;

	} else if ( dynamic_cast<HourlyClassification*>(pc) != 0 ) {
		// HourlyClassification
		HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
		_out << "HourlyClassification" << std::endl;
		_out << hc->GetHourlySalaried() << std::endl;
		std::vector<TimeCard> timecards = hc->GetTimeCards();
		_out << timecards.size() << " ";
		for ( std::vector<TimeCard>::iterator it = timecards.begin();
			it != timecards.end();
			++it ) {
				_out << it->GetDate() << "\t";
				_out << it->GetHours() << std::endl;
		}


	} else if ( dynamic_cast<CommisionClassification*>(pc) != 0 ) {
		// CommisionClassification
		CommisionClassification* cc = dynamic_cast<CommisionClassification*>(pc);
		_out << "CommisionClassification" << std::endl;
		_out << cc->GetSalaried() << std::endl;
		_out << cc->GetRate() << std::endl;
		std::vector<SalesReceipt> receipts = cc->GetSalesReceipts();
		_out << receipts.size() << " ";
		for ( std::vector<SalesReceipt>::iterator it = receipts.begin();
			it != receipts.end();
			++it ) {
				_out << it->GetDate() << "\t";
				_out << it->GetAmount() << std::endl;
		}
	} else {

	}

	// output the employee payment schedule
	PaymentSchedule * ps = e->GetPaymentSchedule();
	if ( dynamic_cast<BiweeklySchedule*>(ps) != 0) {
		_out << "BiweeklySchedule" << std::endl;
	} else if ( dynamic_cast<MonthlySchedule*>(ps) != 0 ) {
		_out << "MonthlySchedule" << std::endl;
	} else if ( dynamic_cast<WeeklySchedule*>(ps) != 0 ) {
		_out << "WeeklySchedule" << std::endl;
	} else { }

	// output the employee payment method
	PaymentMethod * pm = e->GetPaymentMethod();
	if ( dynamic_cast<PaymentMethod*>(pm) != 0) {
		_out << "PaymentMethod" << std::endl;
	} else { }
}

IOSupport::IOSupport( const std::string &name, int type )
: IOHelp(name, type)
{
}

IOSupport::~IOSupport()
{
	if (_in.is_open()) { _in.close(); }
	if (_out.is_open()) { _out.close(); }
}