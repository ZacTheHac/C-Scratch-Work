// CIS023_S2015_Lab9 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct StudentType{
	string sFirstName;
	string sLastName;
	short shScore;
	char cGrade;
};

char calcGrade(short shPercent){
	if (shPercent >= 90){
		return 'A';
	}
	else if (shPercent >= 80){
		return 'B';
	}
	else if (shPercent >= 70){
		return 'C';
	}
	else if (shPercent >= 60){
		return 'D';
	}
	else{
		return 'F';
	}
}

StudentType parse_StudentString(string sInput){
	StudentType stuReturn;//the student struct that will be returned
	string sSplitData[3];//temporary holding array
	string sTemp;//temporary holding string
	short sCounter = 0;//keep track of where I am in the temp holdingh array
	for each (char cLetter in sInput)
	{
		if (cLetter != ' '){//if it's not a space (the terminator of the data block):
			sTemp += cLetter;//concat it to sTemp
		}
		else{
			sSplitData[sCounter] = sTemp;//otherwise: store the current string
			sTemp = "";//clear sTemp
			sCounter++;//and go to the next index in the array
		}
	}
	sSplitData[sCounter] = sTemp;//store the final line(as it's not space-terminated)
	stuReturn.sFirstName = sSplitData[0];
	stuReturn.sLastName = sSplitData[1];
	stuReturn.shScore = stoi(sSplitData[2]);//convert the string into a usable number
	stuReturn.cGrade = calcGrade(stuReturn.shScore);//just do this calculation here

	return stuReturn;
}

string studentToString(StudentType stuInput){
	return stuInput.sLastName + ", " + stuInput.sFirstName + "	" + to_string(stuInput.shScore) + "	" + stuInput.cGrade + "\n";//yes, I could've done this in-line, but I like making useless functions
}

int _tmain(int argc, _TCHAR* argv[])
{
	StudentType stuStudents[30];
	short shCounter = 0;//keeps track of where I am in the array
	string sLine;//the current line
	cout << "Reading the input file at \"CIS023_S2015_Lab9_Data.txt\"\n";
	ifstream fileInput("CIS023_S2015_Lab9_Data.txt");//open the file
	if (fileInput.is_open()){//check that it opened fine
		while (getline(fileInput, sLine))
		{
			stuStudents[shCounter] = parse_StudentString(sLine);//parse the input string, and put it into my array
			shCounter++;
		}
		fileInput.close();
		//done reading
		cout << "Creating the output file at \"CIS023_S2015_Lab9_Output.txt\"\n";
		ofstream fileOutput("CIS023_S2015_Lab9_Output.txt");
		if (fileOutput.is_open()){
			fileOutput << "Last Name, First Name	Score	Grade\n";
			for each (StudentType stuStudent in stuStudents)
			{
				fileOutput << studentToString(stuStudent);
			}
			fileOutput.close();
			cout << "Student records were successfully written to \"CIS023_S2015_Lab9_Output.txt\"!\n";
		}
		else{//couldn't create an output file
			cout << "There was an error writing to \"CIS023_S2015_Lab9_Output.txt\":\n the file could not be created/written to.\n";
		}
	}
	else{//if it didn't: spit out an error and skip all the processing
		cout << "There was an error reading \"CIS023_S2015_Lab9_Data.txt\":\n the file could not be opened.\n";
	}
	system("pause");
	return 0;
}

