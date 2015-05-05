// CIS023_S2015_Lab5 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool c_isNumber(char cLetter){
	char cNumbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };//array of valid characters
	for each (char cTestLetter in cNumbers)
	{
		if (cLetter == cTestLetter){//loop though the array until we find one that matches our input
			return true;//we found the char is a number, return true
		}
	}
	return false;//if it got here, the char wasn't part of the numbers array
}

bool s_isNumber(string sInput){
	for each (char cLetter in sInput)
	{
		if (c_isNumber(cLetter)){//loop through each char in the string, and check if it's a number
			continue;//if it is, keep going
		}
		else{
			return false;//if a single character isn't a number, then we just stop and return false
		}
	}
	return true;//if it went through the entire string without finding a single error, then every character in it is a number
}

int _tmain(int argc, _TCHAR* argv[])
{
	string sInput;//holds the user's input
	int iSum = 0;//holds the sum of the digits
	long long llProduct = 1;//nultiplication gets very very large very very fast. also I just wanted to use a long long. start with 1 because starting at 0 would always make the product 0
	bool bValidInput = false;//says if the input was valid (for the while loop)
	while (!bValidInput){
		cout << "Please input a positive integer";
		cout << endl;
		cin >> sInput;//put the input line into sInput
		cout << endl;
		if (s_isNumber(sInput)){
			bValidInput = true;//if the string only contains numbers, then we make sure the loop doesn't come back
		}
		else{
			bValidInput = false;
			cout << "Sorry, \"" << sInput << "\" doesn't seem to be a valid positive integer.";//otherwise: let the user know something was wrong, and ask again.
			cout << endl;
		}
	}//will loop back for a valid input if the input wasn't valid
	cout << "The digits are: ";
	for each (char cInput in sInput)
	{
		cout << cInput << " ";//output the character, and a space, 1 at a time.
	}
	cout << endl;
	cout << "The sum of those digits is: ";
	for each (char cInput in sInput)
	{
		
		iSum += static_cast<short>(cInput) - '0';//I already verified that it had to be a number, and casting a char returns the ascii value, so I offset it by the ascii value of '0'
	}
	cout << iSum;//output the sum
	cout << endl;
	cout << "The product of those digits is: ";
	for each (char cInput in sInput)
	{
		llProduct *= static_cast<int>(cInput) - '0';//same thing with the offset here
	}
	cout << llProduct;
	cout << endl;
	system("pause");//this is better than using a cin, and the document didn't specify using cin this time

	return 0;
}