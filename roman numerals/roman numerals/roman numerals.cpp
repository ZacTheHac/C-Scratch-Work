// roman numerals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

string intToNumeral(unsigned int iInput){
	string ones[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	string tens[10] = { "", "X", "XX", "XXX", "XC?" };
	return to_string(iInput);
}


int _tmain(int argc, _TCHAR* argv[])
{
	string strTemp;
	unsigned int iInput;
	cout << "enter normal number: ";
	cin >> strTemp;
	iInput = stoi(strTemp);
	cout << intToNumeral(iInput);
	system("pause");
	return 0;
}

