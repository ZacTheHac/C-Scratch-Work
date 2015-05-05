// Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
bool isPalinDrome(string sz_in, int iPoint = 0){
	//I would just like to say that I do not condone the use of recursion here.
	//it is a horrible way to program, as it is very rare that recursion is required to solve a problem
	int iLength = sz_in.size() - 1;//I would always be subtracting 1 to get array index, just do it here
	if (sz_in[iPoint] == sz_in[iLength - iPoint]){
		if (iLength == iPoint){//if these letters are equal and we're at the max, then we're done. all the trues will cascade down
			return true;//this is only ever called on the very last letter
		}
		else{
			if (isPalinDrome(sz_in, ++iPoint)){//remember to increment BEFORE sending it
				return true;
			}
			else{
				return false;//if any of them return false, everything returns false
			}
		}
	}
	else{
		return false;//this returns any time the letters are not equal, no use recurring any deeper, sends false all the way back up the chain.
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string sInput;
	cin >> sInput;
	for (int i = 0; (i < sInput.size()); i++)
	{
		sInput[i] = tolower(sInput[i]);
	}//bring everything to lowercase
	cout << "Input: " << sInput << endl;
	cout << "Is PalinDrome: " << isPalinDrome(sInput) << endl;
	system("pause");
	return 0;
}

