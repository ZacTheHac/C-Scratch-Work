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
		TCHAR DatString[100];
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
	NumNodeStruct* TraverseFind(TCHAR[]);
	int getLength(TCHAR[])const;
	int getLength(CHAR[])const;
	int compare(TCHAR[], TCHAR[], bool, bool)const;
	void copy(TCHAR from[], TCHAR to[]);
	void copy(CHAR from[], TCHAR to[]);
};

