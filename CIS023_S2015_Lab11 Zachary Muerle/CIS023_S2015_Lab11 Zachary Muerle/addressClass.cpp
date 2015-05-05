#include "stdafx.h"
#include "addressClass.h"

addressClass::addressClass(){}
addressClass::addressClass(string sIn)
{
	string sSplitData[4];//temporary holding array
	string sTemp;//temporary holding string
	short sCounter = 0;//keep track of where I am in the temp holding array
	for each (char cIn in sIn)
	{
		if (cIn != ','){//if it's not a comma (the terminator of the data block):
			sTemp += cIn;//concat it to sTemp
		}
		else{
			sSplitData[sCounter] = sTemp;//otherwise: store the current string
			sTemp = "";//clear sTemp
			sCounter++;//and go to the next index in the array
		}
	}
	sSplitData[sCounter] = sTemp;//store the final line(as it's not comma-terminated)

	sAddress = sSplitData[0];
	sCity = sSplitData[1];
	sState = sSplitData[2];
	sZipCode = sSplitData[3];
}

addressClass::addressClass(string Address, string City, string State, string Zip){
	sAddress = Address;
	sCity = City;
	sState = State;
	sZipCode = Zip;
}

string addressClass::getFormattedAddress(){
	return sAddress + ", " + sCity + ", " + sState + ", " + sZipCode;
}

addressClass::~addressClass()
{
}
