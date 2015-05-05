#include "stdafx.h"
#include "contactClass.h"

contactClass::contactClass()
{
}
contactClass::contactClass(string sInput){
	string sSplitData[7];//temporary holding array
	string sTemp;//temporary holding string
	short sCounter = 0;//keep track of where I am in the temp holding array
	for each (char cIn in sInput)
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

	nName = nameClass(sSplitData[0], sSplitData[1]);//based on the names, I assumed the names were formatted given,family
	aAddress = addressClass(sSplitData[2], sSplitData[3], sSplitData[4], sSplitData[5]);
	pPhone = phoneClass(sSplitData[6]);
}

string contactClass::getContactString(){
	return nName.getNameFamilyGiven() + " / " + aAddress.getFormattedAddress() + " / " + pPhone.getFormattedNumber();
}

contactClass::~contactClass()
{
}
