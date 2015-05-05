#include "stdafx.h"
#include "nameClass.h"

nameClass::nameClass(){}
nameClass::nameClass(string Given, string Family)
{
	sGiven = Given;
	sFamily = Family;
}
string nameClass::getNameFamilyGiven(){//I return it in the opposite order it's given to me, yes. but if it's comma delimited then it should be family,given
	return sFamily + "," + sGiven;
}


nameClass::~nameClass()
{
}
