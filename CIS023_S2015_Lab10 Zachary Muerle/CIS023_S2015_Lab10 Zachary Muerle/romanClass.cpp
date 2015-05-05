#include "stdafx.h"
#include "romanClass.h"


romanClass::romanClass(int iInput)
{
	iNormal = iInput;
}

romanClass::romanClass(string sInput)
{
	if (isNumber(sInput))
		iNormal = stoi(sInput);//funny thing: if this breaks, it just throws back 0, which is not between 1 and 3999.
	//you do have to tell it to continue while in debugging, but it only breaks if the first character is not a number.
	//it just stops as soon as it finds a non-number character, returning the begining.
	//I'll just do a manual check before parsing it
	else
		iNormal = -1;//throw back a -1, a number that is inpossible for roman numerals
}


romanClass::~romanClass()
{
}

bool romanClass::verifyBetween(int iLow, int iHigh){
	if (iNormal <= iLow || iNormal >= iHigh){
		return false;
	}
	return true;
}

void romanClass::setNumber(int iInput){
	iNormal = iInput;
}

void romanClass::printRoman(){
	cout << getRoman();
}

bool romanClass::isNumber(string sIn){
	for each (char cIn in sIn)
	{
		switch (cIn)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break;
		default:
			return false;
			break;
		}

	}
	return true;
}

string romanClass::getRoman(){
	string sNumber = to_string(iNormal);
	string sCurrent = "";
	string sReturn = "";
	string ones[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	string tens[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	string hundreds[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	string thousands[10] = { "", "M", "MM", "MMM", "MMMM", "[V]", "[V]M", "[V]MM", "[V]MMM", "[IX]" };//the roman system of "no more than 3 in a row" breaks down here. also ◌̅V doesnt display properly, so I put them in brakets, even though we don't need them
	for (int i = sNumber.length() - 1; i >= 0; i--){
		sCurrent = sNumber[i];
		int iCurrent = stoi(sCurrent);
		if (i == sNumber.length() - 1){
			sReturn = ones[iCurrent]+sReturn;
		}
		else if (i == sNumber.length() - 2){
			sReturn = tens[iCurrent] + sReturn;
		}
		else if (i == sNumber.length() - 3){
			sReturn = hundreds[iCurrent] + sReturn;
		}
		else if (i == sNumber.length() - 4){
			sReturn = thousands[iCurrent] + sReturn;
		}
		//I only did up to 4 digits, because we're not going any higher
	}
	
	
	
	
	return sReturn;
	//I'm actually rather happy with how this turned out. I originally planned a more elegant solution that would generate it procedurally, then double-check, but this works fine.
}
