// juice class 2 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cashRegister CR(500);
	cout << "Current coin = " << CR.getCurrentBalance() << ".\n";
	CR.acceptAmount(28372);
	cout << "Current coin = " << CR.getCurrentBalance() << ".\n";
	CR.acceptAmount(-237846);
	cout << "Current coin = " << CR.getCurrentBalance() << ".\n";

	system("pause");
	return 0;
}

