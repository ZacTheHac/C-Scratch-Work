// CIS023_S2015_Lab11 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	contactClass contacts[24];//there are 24 contacts in the file.
	{//load file
		cout << "Loading from file \"CIS023_S2015_Lab11_Data.txt\"...\n";
		short shCounter = 0;
		string sLine;
		ifstream fileInput("CIS023_S2015_Lab11_Data.txt");//open the file
		if (fileInput.is_open()){//check that it opened fine
			while (getline(fileInput, sLine))
			{
				contacts[shCounter] = contactClass(sLine);
				shCounter++;
			}
			fileInput.close();
			cout << "Data successfully read!\n";
			cout << "Contacts Read:\nFamily,Given name / Address, City, State, Zip / Phone #\n\n";
			for each (contactClass contact in contacts)
			{
				cout << contact.getContactString();
				cout << "\n";
			}
		}
		else{
			cout << "The file \"CIS023_S2015_Lab11_Data.txt\" was unable to be opened.\n";
		}
	}
	system("pause");
	return 0;
}

