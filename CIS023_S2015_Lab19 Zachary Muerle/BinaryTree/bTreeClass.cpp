#include "stdafx.h"
#include "bTreeClass.h"
#include <fstream>
#include <iostream>
using namespace std;


bTreeClass::bTreeClass(void)
{
}


bTreeClass::~bTreeClass(void)
{
	//keep a LL of all the nodes not yet cleared
	//try clearing all left-hand data first, then go through
	//each of the unfinished nodesdoing the same thing.
	//so 2 loops inside of eachother:
	//the main one saying that is the LL isn't empty, grab the next one
	//inner one traversing the nodes, making a note of any righthand ones
	//eventually the nodes will have no children at all, and then when they are deleted, everything is gone.

	//^just thoughts on how to make a proper destructor. no need to do it in this lab as the tree is only built once
}


void bTreeClass::init(HWND hWnd)
{

		// create the input edit box
   hEditIN = CreateWindow(TEXT("EDIT"), TEXT(""),
	   WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 
	   10, 10, 225, 22,
	   hWnd, NULL, NULL, NULL);

		// create the output edit box
   hEditOut = CreateWindow(TEXT("EDIT"), TEXT(""),
	   WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_READONLY, 
	   10, 50, 225, 22,
	   hWnd, NULL, NULL, NULL);

   		// create the Search button
	hSearch = CreateWindow(TEXT("BUTTON"), TEXT("Search"), 
		WS_VISIBLE | WS_CHILD, 
		80, 100, 65, 22, 
		hWnd, HMENU(ID_SEARCH), NULL, NULL);

		// read the input file and build the binary tree here
	if ( BuildTree() != 0 )
		MessageBox(hWnd, _T("Failed to open data file"), _T("File I/O Error"), NULL);


}

int bTreeClass::getLength(TCHAR input[])const{
	int counter = 0;
	TCHAR inp;
	while (true){
		inp = input[counter];

		if (inp == NULL){
			break;
		}
		counter++;
	}
	return counter;
}
int bTreeClass::getLength(CHAR input[])const{
	int counter = 0;
	CHAR inp;
	while (true){
		inp = input[counter];

		if (inp == NULL){
			break;
		}
		counter++;
	}
	return counter;
}
int bTreeClass::compare(TCHAR input1[], TCHAR input2[], bool caseSensitive = false, bool startsWith = false)const{//0 means they're equal, -1 means one is bigger, 1 means 2 is bigger
	int length;
	bool equalLength = false;
	int in1Length = getLength(input1);
	int in2Length = getLength(input2);

	if (in1Length < in2Length){
		length = in1Length;
	}
	else if (in1Length == in2Length){
		length = in1Length;
		equalLength = true;
	}
	else{
		length = in2Length;
	}
	TCHAR SS, inp;
	for (int i = 0; i < length; i++){
		SS = input1[i];
		inp = input2[i];
		if (!caseSensitive){
			SS = towupper(SS);
			inp = towupper(inp);
		}

		if (SS == inp){
			continue;
		}
		else if (SS > inp){
			return -1;
		}
		else{
			return 1;
		}
	}
	//it got out of the loop without determining a winner. so they're equal, up to the length of the shorter
	if (startsWith){
		return 0;
	}
	else{
		if (equalLength)// as long as the length is equal, they're equal
			return 0;
		else{//if the length is not equal, then the shorter one wins.
			if (length == in1Length){
				return -1;
			}
			else{
				return 1;
			}
		}
	}
}
void bTreeClass::copy(TCHAR from[], TCHAR to[]){
	int length = getLength(from);
	for (int i = 0; i < length; i++)
	{
		to[i] = from[i];
	}
	to[length] = NULL;
}
void bTreeClass::copy(CHAR from[], TCHAR to[]){
	int length = getLength(from);
	for (int i = 0; i < length; i++)
	{
		to[i] = from[i];
	}
	to[length] = NULL;
}

// read the file 100names.txt into a linked list
int bTreeClass::BuildTree()
{
	NumNodeStruct *newNode;
	CHAR input[100];

	ifstream inFile;
	inFile.open("..\\100names.txt");
	if (inFile.fail())
		return 1;
	else
	{
		rootNode = nullptr; // rootNode is declared in header

		while (!inFile.eof())
		{
			// read a line from the file
			try {
				inFile.getline(input,100);
				//inFile >> sInput;
				//inFile.read(cInput, 1);
			} catch (...) {
				return 1; 
			}

			// create a new node
			newNode = new NumNodeStruct;
			copy(input, newNode->DatString);
			newNode->LeftLink = nullptr;
			newNode->RightLink = nullptr;

			if ( rootNode == nullptr ) // if this is the top of the file, build the root node
			{
				rootNode = newNode;

			}
			else // add to the list
			{
				TraverseInsert(newNode);
			}
		}

	inFile.close();
	}

	return 0;
}

void bTreeClass::TraverseInsert(NumNodeStruct* insert){
	NumNodeStruct* ParentNode;
	if (rootNode == nullptr)
		return;
	ParentNode = rootNode;
	//main loop
	bool done = false;
	while (!done){

		int result = compare(ParentNode->DatString, insert->DatString, false, false);

		if (result == -1){///less than, go left
			if (ParentNode->LeftLink != nullptr)
				ParentNode = ParentNode->LeftLink;
			else{//this is where we insert
				ParentNode->LeftLink = insert;
				done = true;
			}
		}
		else if (result == 1)//greater than, go right
		{
			if (ParentNode->RightLink != nullptr)
				ParentNode = ParentNode->RightLink;
			else{//this is where we insert
				ParentNode->RightLink = insert;
				done = true;
			}
		}
		else{//they must be equal, so just fail out. I'm not handling duplicates
			return;
		}
	}
}

bTreeClass::NumNodeStruct* bTreeClass::TraverseFind(TCHAR SearchData[]){
	NumNodeStruct* CurrentNode = rootNode;
	int result;
	while (true){//it'll auto-break when it's done
		result = compare(SearchData, CurrentNode->DatString, false, true);
		if (result == 0){
			return CurrentNode;
		}
		else if (result == 1){
			if (CurrentNode->LeftLink != nullptr)
				CurrentNode = CurrentNode->LeftLink;
			else
				return nullptr;
		}
		else{
			if (CurrentNode->RightLink != nullptr)
				CurrentNode = CurrentNode->RightLink;
			else
				return nullptr;
		}
	}

	return nullptr;
}
// Search for a string in the tree
void bTreeClass::Search(HWND hWnd)
{
	NumNodeStruct* FoundNode;
	TCHAR szInput[100];
	TCHAR szOutput[100];
	GetWindowText(hEditIN, szInput, 100);
	FoundNode = TraverseFind(szInput);
	if (FoundNode == nullptr){
		_tcscpy_s(szOutput, 100, _T("Record not found"));
	}
	else{
		//_stprintf_s(szOutput, _T("%d"), FoundNode->DatString);
		copy(FoundNode->DatString, szOutput);//you use your francy built-in functions and I'll build my own that are prone to breaking if you feed them irregular data
	}
	SetWindowText(hEditOut, szOutput);


		//MessageBox(hWnd, _T("Insert your search code here"),_T("CALLBACK WndProc"),NULL);
}

