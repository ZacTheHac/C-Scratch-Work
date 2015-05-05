#pragma once
class romanClass
{
public:
	romanClass();
	~romanClass();
	//public get/sets
	void SetValue(string sz_in);
	string GetValue();
	//all the operators:
	bool operator==(const romanClass& otherRoman);
	bool operator>(const romanClass& otherRoman);
	bool operator<(const romanClass& otherRoman);
	string operator+(const romanClass& otherRoman);
	string operator-(const romanClass& otherRoman);
	void operator++();
	void operator--();
private:
	//internal conversion functions
	int getIntFromRoman(string);
	string getRoman(int);
	int value; //holds the actual value of the roman numeral (much easier & more compact than storing the roman)
};

