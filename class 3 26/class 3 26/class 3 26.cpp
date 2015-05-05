// class 3 26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*struct nodeType
{
	int info;
	nodeClass *nextLink;//pointer to next object
	nodeClass *prevLink;
};*/

int _tmain(int argc, _TCHAR* argv[])
{
	/*nodeClass newNode;
	newNode.info = 6;
	cout << newNode.info << endl;*/
	nodeClass *first, *last, *newNode;
	int num;
	first = nullptr;
	last = nullptr;//empty them, because.
	while (true)
	{
		cout << "enter an integer (-999 to terminate): ";
		cin >> num;
		if (num != -999){
			newNode = new nodeClass;//create the spot in memory
			newNode->info = num;//remember that it's only a pointer, not the actual object
			newNode->nextLink = nullptr;
			newNode->prevLink = nullptr;

			if (first == nullptr){
				first = newNode;
				last = newNode;
			}
			else{
				last->nextLink = newNode;
				newNode->prevLink = last;
				last = newNode;
			}
		}
		else{
			break;
		}

	}
	nodeClass *currentNode;
	currentNode = first;
	int count = 0;
	while (currentNode != nullptr){//print them out
		cout << "Record #" << ++count << ":" << currentNode->info << endl;
		currentNode = currentNode->nextLink;
	}
	cout << endl;
	currentNode = last;
	while (currentNode != nullptr){//print them out in reverse
		cout << "Record #" << count-- << ":" << currentNode->info << endl;
		currentNode = currentNode->prevLink;
	}
	//inserting a new node:
	cout << "Enter a number to insert: ";
	cin >> num;
	newNode = new nodeClass;
	newNode->info = num;
	newNode->nextLink = nullptr;
	newNode->prevLink = nullptr;
	//hardcoding into 3rd spot:
	count = 1;
	currentNode = first;
	while (count < 2){//get the third node(I know it says 2, but roll with me here, we have to mess with 2 to insert ourselves into 3)
		currentNode = currentNode->nextLink;
		count++;
	}
	newNode->prevLink = currentNode;
	newNode->nextLink = currentNode->nextLink;//link up this node
	currentNode->nextLink = newNode;
	newNode->nextLink->prevLink = newNode;//link up the surrounding

	currentNode = first;
	count = 0;
	while (currentNode != nullptr){//print them out
		cout << "Record #" << ++count << ":" << currentNode->info << endl;
		currentNode = currentNode->nextLink;
	}
	cout << endl;
	currentNode = last;
	while (currentNode != nullptr){//print them out in reverse
		cout << "Record #" << count-- << ":" << currentNode->info << endl;
		currentNode = currentNode->prevLink;
	}



	cout << endl;
	system("pause");
	return 0;
}

