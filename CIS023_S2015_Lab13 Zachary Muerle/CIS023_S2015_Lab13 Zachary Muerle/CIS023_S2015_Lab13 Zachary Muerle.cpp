// CIS023_S2015_Lab13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	// declare two objects of type romanClass
	romanClass roman1;
	romanClass roman2;

	// Get two roman numerals
	string sz_Input;
	cout << "Line 1: Enter first roman numeral (I to IX): ";
	getline(cin, sz_Input);
	roman1.SetValue(sz_Input);	// Assume input will always be I, II, III, IV, V, VI, VII, VIII, or IX
	// don't bother to trap bad input

	cout << "Line 2: Enter second roman numeral (I to IX): ";
	getline(cin, sz_Input);
	roman2.SetValue(sz_Input);	// Assume input will alway be I, II, III, IV, V, VI, VII, VIII, or IX
	// don't bother to trap bad input

	// display the values of the two objects
	cout << "Line3: roman1.GetValue() = " << roman1.GetValue() << endl;
	cout << "Line4: roman2.GetValue() = " << roman2.GetValue() << endl;

	// compair the objects, display true/false
	if (roman1 == roman2)
		cout << "Line5: roman1 == roman2\n";
	else if (roman1 > roman2)
		cout << "Line6: roman1 > roman2\n";
	else if (roman1 < roman2)
		cout << "Line7: roman1 < roman2\n"; // Remember, IX is not less than VIII

	// add the two objects
	cout << "Line 8: roman1 + roman2 = " <<
		roman1 + roman2 << endl;

	// subtract the two objects 
	if (roman1 > roman2) // this prevents 0 or negative result
		cout << "Line 9: roman1 - roman2 = " <<
		roman1 - roman2 << endl;

	// and lastly, increment the first object and decrement the second
	++roman1; // assume both values between I and IX
	--roman2; // do nothing if result is 0
	cout << "Line10: ++roman1 = " << roman1.GetValue() << endl;
	cout << "Line11: --roman2 = " << roman2.GetValue() << endl;


	cout << endl;
	system("pause");
	return 0;
}
