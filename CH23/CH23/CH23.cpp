// CH23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	string sMovieName;
	double dAdultTicketPrice;
	int iNoOfAdultTicketsSold;
	double dGrossAmount;

	cout << "Enter a movie name: ";//print that line to the console
	//cin >> sMovieName;//get input from console and store it in movieName. cin removes all blank characters
	getline(cin, sMovieName);//get the line from the console input and store it in movieName
	cout << endl;//make sure it goes to the next line when the input is finished

	cout << "Enter the price of an adult ticket: ";
	cin >> dAdultTicketPrice; //if you put in a number, it works, but if you put in NaN, it's the largest negative number (all 1) because it fails, and just continues with the initial value
	cout << endl;

	cout << "Enter the number of adult tickets sold: ";
	cin >> iNoOfAdultTicketsSold;
	cout << endl;

	dGrossAmount = iNoOfAdultTicketsSold * dAdultTicketPrice;
	
	//Gross Amount: ............................$32.57
	cout << "Gross Amount: " << setfill('.') << setw(8)/*set width. this is where the fill is inserted*/ << '$' <<dGrossAmount;
	/*
	cout << sMovieName;
		cout << " made $";
		cout << dGrossAmount;
		cout << endl;
		//you can also do movieName << "made $" << grossAmount << endl
	*/


	return 0;

	/*
	int i = 1;
	i = 5;
	bool b;
	b = true;
	char c;
	c = 'F';
	long l;
	l = 3.14159;
	float f;
	f = 3.14159f;
	long long SL;
	SL = 64;//64 bytes. time to waste all the system RAM!
	char s[4] = "dog";
	string s1 = "this is an easier way to define string";
	i = 1;
	int j = 2;
	int k = 3;
	k = i + j;
	k = i * j;
	k = i - j;
	k = i / j;
	k = i % j;
	f = i / j;//still 0 because it's division of 2 integers, doesn't care what the storage is
	k = i * j + i * j;//1*2+1*2: order of op=4, w/o: 6. C gets 4, meaning that C is a smart language that can follow the order of op, java doesn't care, and would get 6
	//casting:
	double d = static_cast<double>(i) / j;//cast i to a double and divide by j finally gets a decimal
	*/
}

