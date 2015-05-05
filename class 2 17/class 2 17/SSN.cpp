#include "stdafx.h"
#include "SSN.h"
using namespace std;


SSN::SSN()
{
}

SSN::SSN(string sz_in)
{
	sz_num = sz_in;
}


SSN::~SSN()
{
}

string SSN::getSSN(){
	return sz_num;
}

bool SSN::compare(string sz_in){
	return sz_num == sz_in;
	//note: string's compare returns 1 for s<S, 0 if s=S, -1 if s>S
}

bool SSN::append(string sz_in){
	//add string to num
	//resrtict: no more than 11 length
	//only numbers and dashes
	if (sz_in.length() + sz_num.length() > 11){//check the length will be fine
		return false;
	}
	for each (char cIn in sz_in)//verify the string only contains numbers and dashes
	{
		switch (cIn)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '-':
			break;
		default:
			return false;
			break;
		}
	}
	
	sz_num += sz_in;//apend if it gets this far
	return true;//return true so the caller knows it worked
}


