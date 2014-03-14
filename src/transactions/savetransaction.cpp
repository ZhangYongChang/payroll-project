#include "savetransaction.h"
#include "proxy.h"
#include "memorypayrolldatabase.h" 

SaveTransaction::SaveTransaction( const std::string& filename ) 
	: itsFileName(filename) {
}

SaveTransaction::~SaveTransaction() {
}

void SaveTransaction::Execute() {
	DBPROXY->Serialize();
}