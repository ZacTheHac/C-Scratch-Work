// CIS023_S2015_Lab16 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Person
{
	string GivenName;
	string FamilyName;
	string City;
	int age;
	string LicenseNumber;
	Person *Child = nullptr;
	/*string outString(){//really just a testing thing. well it was. now it's how I output data. Removed from here because a func in a struct is bad
		return FamilyName + ", " + GivenName + " City:" + City + " Age:" + to_string(age) + " DL#:" + LicenseNumber;
		
	}*/
};

string personToString(Person *Pointer){
	return Pointer->FamilyName + ", " + Pointer->GivenName 
		+ " City:" + Pointer->City 
		+ " Age:" + to_string(Pointer->age) 
		+ " DL#:" + Pointer->LicenseNumber;
}

Person ParseInput(string input){
	string sTemp;
	Person toReturn;
	int counter = 0;
	for each (char cTemp in input)
	{
		if (cTemp != ' '){
			sTemp += cTemp;
		}
		else{
			switch (counter)
			{
			case 0://family
				toReturn.FamilyName = sTemp;
				break;
			case 1://given
				toReturn.GivenName = sTemp;
				break;
			case 2://city
				toReturn.City = sTemp;
				break;
			case 3://age
				toReturn.age = stoi(sTemp);
				break;
			case 4://DL#
				toReturn.LicenseNumber = sTemp;//good thing there's a space on the end, or I would have to put this outside.
				break;
			default:
				break;
			}
			counter++;
			sTemp.clear();
		}

	}
	return toReturn;
}

Person * LinkListGetRecord(int i, Person *First){
	int counter = 1;
	Person *Current = First;
	while (counter < i){
		Current = Current->Child;
		counter++;
	}
	return Current;
}

Person * ToPointer(Person &object){
	//note that this makes a whole new object, it doesn't just magically find the pointer to the object
	Person *Pointer = new Person;
	Pointer->GivenName = object.GivenName;
	Pointer->FamilyName = object.FamilyName;
	Pointer->City = object.City;
	Pointer->age = object.age;
	Pointer->LicenseNumber = object.LicenseNumber;
	return Pointer;
}

void printRecord(Person *personPointer, int RecordNumber){
	cout << "Record #";
	cout << setfill('0') << setw(3) << RecordNumber << ": ";
	cout << setfill(' ') << setw(55) << personToString(personPointer) << endl;//I could fiddle with this a bit more to make it look really good, but it's fine.
}

void printList(Person *Start){
	Person *currentNode = Start;
	int count = 1;
	while (true){
		currentNode = LinkListGetRecord(count, Start);
		if (currentNode != nullptr){
			printRecord(currentNode, count);
			count++;
		}
		else
			break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Person *llStart = nullptr, *llLatest = nullptr, *llCurrent, personHolder;//start of the list, last record, a work ptr, and work object
	ifstream inputFile;
	string fileLine;
	int iRecord;
	int recordsRead = 0;
	cout << "Attempting to open \"CIS023_S2015_Lab16_Data.txt\"...\n";
	inputFile.open("CIS023_S2015_Lab16_Data.txt");
	if (inputFile.is_open()){
		cout << "File Successfully Loaded!\n";
		try{
			while (getline(inputFile, fileLine))//read the file
			{
				personHolder = ParseInput(fileLine);//parse the line into an object
				//cout << personHolder.outString() << endl;//display it (for debugging)
				llCurrent = ToPointer(personHolder);
				if (llStart == nullptr){
					llStart = llCurrent;//init the list
					llLatest = llCurrent;
				}
				else{
					llLatest->Child = llCurrent;//add it to the list
					llLatest = llCurrent;//move the "latest" reference
				}
				recordsRead++;
			}
			cout << "File Successfully Read.\n";
		}
		catch (...){
			cout << "There was an error reading the data from the file.\n";
		}
		inputFile.close();//odd thing: it'll suggest a "finally" block, but c++ doesn't support it. which is fine, this is better, visually, anyways.
		//printList(llStart);//this was left for debugging: it prints the entire list.
		cout << recordsRead << " records successfully read!\n";
		do{
			cout << "Enter a record number (1 - "<<recordsRead<< "): ";//boom! dynamic! because that's the whole point of using linked lists in this scenario: unknown # of records.
			cin >> iRecord;
			if (iRecord <= recordsRead && iRecord >= 1)
				break;
			cout << "The number must be between 1 and "<<recordsRead<<", inclusive.\n";
			cin.clear();//clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore everything in there currently.
			//fun thing, that. if it doesn't work proper, it just does an infinite loop, unless you clean out cin manually. because flush isn't a thing apparently, except for fflush, but that only works for windows, it seems
		} while (true);//this will loop until cin successfully goes into iRecord with a value between 1 and 100
		printRecord(LinkListGetRecord(iRecord, llStart), iRecord);

	}
	else{
		cout << "There was an error reading the file.\n";
	}
	system("pause");
	return 0;
}

