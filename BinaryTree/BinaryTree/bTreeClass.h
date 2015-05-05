#pragma once

	#define ID_SEARCH		1001	// ID for Search button


class bTreeClass
{
public:
	bTreeClass(void);
	~bTreeClass(void);

	void init(HWND);
	void Search(HWND);

private:

	struct NumNodeStruct
	{
		int iData;
		NumNodeStruct *LeftLink;
		NumNodeStruct *RightLink;

	};

	HWND hEditIN;					// handle for input edit box
	HWND hEditOut;					// handle for output edit box
	HWND hSearch;					// handle for search button
	NumNodeStruct *rootNode;		// root node of tree

		// private methods
	int BuildTree();
	void TraverseInsert(NumNodeStruct* insert);
	NumNodeStruct* TraverseFind(int);
};

