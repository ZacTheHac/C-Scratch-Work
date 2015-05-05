// class 1 29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

namespace NationsType{
	string name;
	double logitude;
	double latitude;
	string capital;
	void showFlag();
}

int _tmain(int argc, _TCHAR* argv[])
{
	enum colors{BROWN, BLUE, GREEN, PINK, ORANGE};//enumerated colors. we don't know the internal value, and we don't care. they're just constants
	
	typedef int BOOLEAN;
	BOOLEAN TRUE = 1;
	//defined a new "BOOLEAN" data type, that is really an int, and define 1 as "TRUE"
	using namespace NationsType; //see above. usually not used, structs are used instead

	string str1 = "doggy";
	str1 = "that doggy in the window 阿部のほけ";
	str1.find("window");


	
	return 0;
}
