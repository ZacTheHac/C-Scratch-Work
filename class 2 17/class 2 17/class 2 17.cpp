// class 2 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string sz_ing;
	sz_ing = "puppies";
	cout << sz_ing.length();
	SSN socNum;
	socNum.append("99-99-999-9-99");
	SSN socNUM2("000-00-0000");
	cout << "SOCNUM2 = " << socNUM2.getSSN() << "\n";
	if (socNUM2.compare("000-00-0000")){
		cout << "True\n";
	}
	else{
		cout << "False\n";
	}
	//cout << "socNUM2 == 000 - 00 - 0000 ?" << socNUM2.compare("000-00-0000") << "\n";

	system("pause");
	return 0;
}

