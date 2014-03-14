#ifndef NOAFFILIATION_H_
#define NOAFFILIATION_H_

#include "affiliations.h"
#include "affiliation.h" 

class AFFILIATIONSAPI NoAffiliation :
	public Affiliation
{
public:
	NoAffiliation();
	virtual ~NoAffiliation();

	virtual double Payment();
}; 

#endif