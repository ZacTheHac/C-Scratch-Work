// class 2 19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SSAN sTemp;
	SSAN Temp2("000-00-0000");
	sTemp.setSSAN("111-11-1111");
	string sz_tmp = sTemp.getSSAN();

	personClass person;
	person.setFirstName("Mark");
	person.setLastName("Berret");
	if (person.setSSAN("000000000")){
		cout << "Valid SSAN\n";
	}
	else{
		cout << "Invalid SSAN\n";
	}
	system("pause");
	return 0;
}

