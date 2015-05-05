// class 2 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct thisType{// end data types with "Type"
	int iOne;
	double dDouble;
	string sMyName;
	int iArray[10];//if you want to do any computation, the struct must be defined inside a function
};
struct pixelType{
	double RED;
	double GREEN;
	double BLUE;
	thisType thingy;
};
struct carType{
	string VIN;
	string Make;
	string Model;
	int Year;
	double Miles;
	string Color;
	double PurchasePrice;
	double SellPrice;
};
const int alot = 500;
carType car[alot];

carType GetCar(){
	carType retCar;
	string strTemp;
	cout << "Enter VIN #:";
	getline(cin, retCar.VIN);

	cout << "Enter Make: ";
	getline(cin, retCar.Make);

	cout << "Enter Model: ";
	getline(cin, retCar.Model);

	cout << "Enter Year: ";
	getline(cin, strTemp);
	retCar.Year = stoi(strTemp);

	cout << "Enter Miles: ";
	getline(cin, strTemp);
	retCar.Miles = stoi(strTemp);

	cout << "Enter Color: ";
	getline(cin, retCar.Color);

	cout << "Enter Purchase Price: ";
	getline(cin, strTemp);
	retCar.PurchasePrice = stoi(strTemp);

	cout << "Enter Sell Price: ";
	getline(cin, strTemp);
	retCar.SellPrice = stoi(strTemp);

	cout << "\n";



	return retCar;
}
void DisplayCar(carType carWork){
	cout << "VIN:" << carWork.VIN << "\n";
	cout << "Make:" << carWork.Make << "\n";
	cout << "Model:" << carWork.Model << "\n";
	cout << "Year:" << carWork.Year << "\n";
	cout << "Miles:" << carWork.Miles << "\n";
	cout << "Color:" << carWork.Color << "\n";
	cout << "Purchase Price:" << carWork.PurchasePrice << "\n";
	cout << "Sell Price:" << carWork.SellPrice << "\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	thisType thingy;
	thingy.dDouble = 100.1;
	thisType doohickey;
	doohickey.dDouble = 23.4;

	pixelType pixel[1024];
	pixel[0].RED = 225;
	pixel[0].thingy.dDouble = pixel[0].RED;

	pixelType secondPixel;
	secondPixel = pixel[0];//however: relational operators do not work

	for each (carType cah in car)
	{
		cah.VIN = "";//init all the data types. clears out the junk in the array
	}
	for (int i = 0; i < alot; car[i++].VIN = "");//i++ means use, THEN increment, ++i = increment, THEN use
	//those 2 loops mean the same thing. jus different ways of doing it
	for (int i = 0; i < 2; i++){
		cout << "Enter data for car #" << i <<":\n";
		car[i] = GetCar();
	}
	for (int i = 0; i < 2; i++){
		cout << "\n\n";
		cout << "Car #" << i << ":\n";
		DisplayCar(car[i]);
	}

	system("pause");
	return 0;
}

