#include "stdafx.h"
#include "Incorrect_Format.h"

Incorrect_Format::Incorrect_Format(string details){
	__Mywhat = details;
}


Incorrect_Format::~Incorrect_Format()
{
}

string Incorrect_Format::what(){
	return __Mywhat;
}
