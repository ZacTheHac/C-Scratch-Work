// class 3 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ClockType MyClock(12, 15, 00);
	ClockType MyClock2;
	//cout << MyClock2.DisplayTime()<<endl;
	MyClock2.SetTime(12, 50, 59);
	for (int i = 0; i < 60; i++)
	{
		MyClock2++;
		cout << MyClock2.DisplayTime() << endl;
	}
	cout << MyClock.DisplayTime() << endl;
	MyClock << "H = 5";
	MyClock << "M = 10";
	MyClock << "S = 11";
	cout << MyClock.DisplayTime() << endl;

	MyClock << "H = 10";
	MyClock << "M = 0";
	MyClock << "S = 1";
	cout << MyClock.DisplayTime() << endl;
	cout << "H = " << MyClock[0];

	cout << endl;
	system("pause");
	return 0;
}

