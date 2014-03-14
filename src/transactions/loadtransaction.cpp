#include "loadtransaction.h"
#include "databaseproxy.h"
#include "proxy.h"

LoadTransaction::LoadTransaction( const std::string& filename ) 
	: itsFileName(filename) {
}

LoadTransaction::~LoadTransaction() {
}

void LoadTransaction::Execute() {
	DBPROXY->DeSerialize();
}