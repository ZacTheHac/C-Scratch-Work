#include "stdafx.h"
#include "divByZero.h"


divByZero::divByZero()
{
	cout << "Divide by 0 error!";
}
divByZero::divByZero(int iIn)
{
	iValue = iIn;
}
int divByZero::GetValue(){
	return iValue;
}


divByZero::~divByZero()
{
}
