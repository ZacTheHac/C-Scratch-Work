#pragma once
class phoneClass
{
public:
	phoneClass();
	phoneClass(string sIn);
	~phoneClass();
	string getFormattedNumber();
	string getUnFormattedNumber();
private:
	string sAreaCode;
	string sMainNumber;//ints are surprisingly small when talking about phone numbers
};

