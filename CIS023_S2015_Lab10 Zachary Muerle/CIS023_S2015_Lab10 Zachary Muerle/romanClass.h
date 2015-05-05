#pragma once
#include <string>
using namespace std;

class romanClass
{
public:
	romanClass(int iInput);
	romanClass(string sInput);
	bool verifyBetween(int iLow, int iHigh);
	~romanClass();
	string getRoman();
	void setNumber(int);
	void printRoman();
private:
	int iNormal;
	bool isNumber(string);
};

