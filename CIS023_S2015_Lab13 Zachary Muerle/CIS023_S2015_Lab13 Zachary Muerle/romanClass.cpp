#include "stdafx.h"
#include "romanClass.h"
const static string romanNumbers[19] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII" };
//define this up here so that I always have access to it inside the code.

romanClass::romanClass()
{
}
romanClass::~romanClass()
{
}

//public get and set functions
void romanClass::SetValue(string sz_in){
	value = getIntFromRoman(sz_in);
}
string romanClass::GetValue(){
	return romanNumbers[value];
}

//internal conversion functions
int romanClass::getIntFromRoman(string sz_in){
	for (int i = 0; i < 20; i++)//have to search the array, and I can't even do a foreach or I won't know where I am
	{
		if (sz_in == romanNumbers[i]){
			return i;
		}
	}
	return 0;//if it's not found, just send a 0. if there's no error checking in main, ther will be no error checking here.
}
string romanClass::getRoman(int iIn){
	return romanNumbers[iIn];
}

//all the operators. pretty much just take the interal values and use the operators on them
//on the off chance it needs to return a string (like with additon and subtraction, as that's how it's written in _tmain) it applies the operations to the value and returns the string in the array with that index.
bool romanClass::operator==(const romanClass& otherRoman){
	return value == otherRoman.value;
}
bool romanClass::operator>(const romanClass& otherRoman){
	return value > otherRoman.value;
}
bool romanClass::operator<(const romanClass& otherRoman){
	return value < otherRoman.value;
}
string romanClass::operator+(const romanClass& otherRoman){
	return romanNumbers[value + otherRoman.value];
}
string romanClass::operator-(const romanClass& otherRoman){
	return romanNumbers[value - otherRoman.value];
}
void romanClass::operator++(){
	value++;
}
void romanClass::operator--(){
	value--;
}
