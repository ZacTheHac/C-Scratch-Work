// class 2 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Die d;
	Die dd(1);
	for (int t = 0; t < 100; t++)
	{
		dd.roll();
		int i = dd.getNum();
		cout << "You rolled " << i << "\n";
	}
	system("pause");
	return 0;
}

