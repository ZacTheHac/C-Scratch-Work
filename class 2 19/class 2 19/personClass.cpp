#include "stdafx.h"
#include "personClass.h"


personClass::personClass()
{
}
void personClass::setFirstName(string sz_FN){
	sz_FirstName = sz_FN;
}
void personClass::setLastName(string sz_LN){
	sz_LastName = sz_LN;
}
bool personClass::setSSAN(string sz_ssn){
	return SSN.setSSAN(sz_ssn);
}


personClass::~personClass()
{
}
