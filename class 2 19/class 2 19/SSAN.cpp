#include "stdafx.h"
#include "SSAN.h"


SSAN::SSAN()
{
}
SSAN::SSAN(string ssn){
	setSSAN(ssn);
}
string SSAN::getSSAN(){
	return SSN;
}
bool SSAN::setSSAN(string ssn){
	if (ssn.length() != 9){
		return false;
	}
	for each (char cIn in ssn)
	{
		//or isDigit(cIn)
		switch (cIn)
		{
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			break;
		default:
			return false;
			break;
		}

	}
	SSN = ssn;
	return true;
}

SSAN::~SSAN()
{
}
