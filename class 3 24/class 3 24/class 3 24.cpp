// class 3 24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct nodeType
{
	int info;
	nodeType *link;//pointer to next object
};

int _tmain(int argc, _TCHAR* argv[])
{
	/*nodeType newNode;
	newNode.info = 6;
	cout << newNode.info << endl;*/
	nodeType *first, *last, *newNode;
	int num;
	first = nullptr;
	last = nullptr;//empty them, because.
	while (true)
	{
		cout << "enter an integer (-999 to terminate): ";
		cin >> num;
		if (num != -999){
			newNode = new nodeType;//create the spot in memory
			newNode->info = num;//remember that it's only a pointer, not the actual object
			newNode->link = nullptr;

			if (first == nullptr){
				first = newNode;
				last = newNode;
			}
			else{
				last->link = newNode;
				last = newNode;
			}
		}
		else{
			break;
		}

	}
	nodeType *currentNode;
	currentNode = first;
	int count = 0;
	while (currentNode != nullptr){
		cout <<"Record #"<<++count<<":"<< currentNode->info << endl;
		currentNode = currentNode->link;
	}



	cout << endl;
	system("pause");
	return 0;
}

