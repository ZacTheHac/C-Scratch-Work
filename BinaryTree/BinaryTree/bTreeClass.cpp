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

// read the file 100names.txt into a linked list
int bTreeClass::BuildTree()
{
	NumNodeStruct *newNode;
	int inputNum;

	ifstream inFile;
	inFile.open("..\\100numbers.txt");
	if (inFile.fail())
		return 1;
	else
	{
		rootNode = nullptr; // rootNode is declared in header

		while (!inFile.eof())
		{
			// read a line from the file
			try {
				inFile >> inputNum;
			} catch (...) {
				return 1; 
			}

			// create a new node
			newNode = new NumNodeStruct;
			newNode->iData = inputNum;
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
		if (insert->iData < ParentNode->iData){///less than, go left
			if (ParentNode->LeftLink != nullptr)
				ParentNode = ParentNode->LeftLink;
			else{//this is where we insert
				ParentNode->LeftLink = insert;
				done = true;
			}
		}
		else if (insert->iData > ParentNode->iData)//greater than, go right
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

bTreeClass::NumNodeStruct* bTreeClass::TraverseFind(int SearchData){
	NumNodeStruct* CurrentNode = rootNode;
	while (true){//it'll auto-break when it's done
		if (SearchData == CurrentNode->iData){
			return CurrentNode;
		}
		else if (SearchData < CurrentNode->iData){
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
	int iSearch = 0;
	GetWindowText(hEditIN, szInput, 100);
	iSearch = _tstoi(szInput);
	FoundNode = TraverseFind(iSearch);
	if (FoundNode == nullptr){
		_tcscpy_s(szOutput, 100, _T("Record not found"));
	}
	else{
		_stprintf_s(szOutput, _T("%d"), FoundNode->iData);
	}
	SetWindowText(hEditOut, szOutput);


		//MessageBox(hWnd, _T("Insert your search code here"),_T("CALLBACK WndProc"),NULL);
}

