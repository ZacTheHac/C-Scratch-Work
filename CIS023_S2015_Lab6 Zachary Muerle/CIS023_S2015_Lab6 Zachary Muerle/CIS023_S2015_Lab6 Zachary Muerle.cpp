// CIS023_S2015_Lab6 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool c_isVowel(char cLetter){
	switch (cLetter){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
		break;//only put this here because of "poor coding practices", it doesn't change the outcome due to how return works
	default:
		return false;
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char cInput;
		cout << "Please input a character: ";
		cin >> cInput;
		cInput = tolower(cInput);
		cout << endl;
		cout << "You input " << cInput;
		if (c_isVowel(cInput)){
			cout << ", which is a vowel.";
		}
		else{
			cout << ", which is not a vowel.";
		}
		cout << endl;
		system("pause");
	return 0;
}

