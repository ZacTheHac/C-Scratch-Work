// class 3 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class divisionByZero{
public:
	void doDivision() throw (divisionByZero){
		cout << "Statement from divbyzero\n";
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	divisionByZero divByZero;
	try{
		divByZero.doDivision();
	}
	catch (divisionByZero dbz){
		cout << "catch code";
	}



	string sInput;
	int iInt;
	getline(cin, sInput);
	try{
		//iInt = stoi(sInput);
		//if (sInput.find("C") < 0)//this doesn't work, because it compares to the class, which is an address, which is undoubtably > 0
		//have to do it in separate steps:
		iInt = sInput.find("C");
		if (iInt < 0)
			throw sInput;//if find returns a -1, it couldn't be found. throw nothing, we have a general catch, so it doesn't matter
	}
	catch (...){//catches all errors
		cout << "Err";
	}

	cout << endl;
	system("pause");
	return 0;
}

