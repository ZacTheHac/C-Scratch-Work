// class 1 27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int z = 1000;
int AreaRect(){
	return -238974;
}
int AreaRect(int h, int w){
	return h*w;
}
int AreaSquare(int& i){
	if (i > 0){
		i = i*i;//this is just bad practice
		return 0;
	}
	else
		return 1;
}
int _tmain(int argc, _TCHAR* argv[]){
	int h;
	int w;
	int a;

	cout << "Enter the height of the rectangle ";
	cin >> h;
	cout << "\nEnter the Width of the rectangle ";
	cin >> w;
	if (h == 0 || w == 0){//if (h==w==0) would work as an and
		a = AreaRect();
	}
	else{
		a = AreaRect(h, w);
	}

	cout << "\nThe area is " << a;

	if (AreaSquare(h) == 0){//if the function returned correctly
		cout << "\nh Squared = " << h;
	}
	cin >> h;

	return 0;
}

/*
void kitty(int inny);//prototype the function, so it can be called anywhere below this

int doggy(){//overloaded function

}
int doggy(int& innx, int& inny, int& innz){//ampersand means it passes by reference
	inny++;
	innx = inny + innz;

	return 0;
}

void kitty(int inny){

}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 100;
	int y = 100;
	int z = 100;
	if (doggy(x,y,z) == 0){//the function ran fine
		if (x < 100);

		if (x >= 100);//this one gets called, because x was modified
	}
	if (doggy()){

	}

	return 0;
}
*/
