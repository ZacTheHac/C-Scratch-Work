#include "stdafx.h"
#include "phoneClass.h"

phoneClass::phoneClass(){}
phoneClass::phoneClass(string sIn)
{
	sAreaCode = sIn.substr(1, 3);
	sMainNumber = sIn.substr(6, 3) + sIn.substr(10, 4);
}
string phoneClass::getFormattedNumber(){
	return "(" + sAreaCode + ") " + sMainNumber.substr(0, 3) + "-" + sMainNumber.substr(3, 4);
}
string phoneClass::getUnFormattedNumber(){
	return sAreaCode + sMainNumber;
}


phoneClass::~phoneClass()
{
}
