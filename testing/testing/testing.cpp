// testing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "F:\Zac Muerle Backup\DATA STRUCTURES\CIS023_S2015_Lab17 Zachary Muerle\CIS023_S2015_Lab17 Zachary Muerle\LinkList.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	short num;
	LinkList<short> lList;
	while (true)
	{
		cout << "enter an integer (-999 to terminate): ";
		cin >> num;
		if (num != -999){
			lList.addRecord(num);
		}
		else{
			break;
		}

	}
	for (int i = 1; i <= lList.getLength(); i++)
	{
		cout << "Record #" << i << ":" << lList.getRecord(i) << endl;
	}
	cout << "Enter a number to insert: ";
	cin >> num;
	int where;
	cout << "Enter where to insert: ";
	cin >> where;
	lList.addRecord(num, where);
	for (int i = 1; i <= lList.getLength(); i++)
	{
		cout << "Record #" << i << ":" << lList.getRecord(i) << endl;
	}
	system("pause");
}

