// Pig Latin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool c_IsVowel(char cLetter){
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };//we count y for the sake of pig latin
	cLetter = tolower(cLetter); //convert it to lowercase
	switch (cLetter){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
		break;//this won't be hit, but it's just convention, in case it isnt a return
	default:
		return false;
	}
}

string rotate(string sInput){
	sInput = sInput.substr(1) + sInput[0] + "ay";
	return sInput;
	//or: by the book...

	string strDone;
	int length = sInput.length();
	strDone = sInput.substr(1, length - 1);
	strDone.append(sInput.substr(0, 1));
	strDone.append("ay");
	return strDone;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string sIn;
	getline(cin, sIn);
	if (c_IsVowel(sIn[0])){
		cout << sIn + "way";
	}
	else{
		cout << rotate(sIn);
	}
	cout << endl;
	system("pause");

	return 0;
}

