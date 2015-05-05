// CIS023_S2015_Lab10 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	string strTemp;
	cout << "enter a number between 1-3999 (inclusive): ";
	cin >> strTemp;
	romanClass rcRoman(strTemp);
	if (rcRoman.verifyBetween(0, 4000)){
			rcRoman.printRoman();
			cout << "\n";
	}
	else{
		cout << "The input number: " + strTemp + " was not a number between 1 and 3999.\n";
	}
	system("pause");
	return 0;
}

