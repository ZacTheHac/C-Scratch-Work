#pragma once


// these definitions SHOULD go in the string table - but that would make them too difficult to find for this demonstration
#define MAX_LOADSTRING	100		// TCHAR array size
#define ID_Right		1001	// ID for > button
#define ID_DblRight		1002	// ID for >> button
#define ID_Left			1003	// ID for < button
#define ID_DblLeft		1004	// ID for << button

class wizzard
{
public:
	wizzard(void);
	~wizzard(void);

	void init(HWND, HINSTANCE);						// initialize (create) the controls

	void ButtonPressed(HWND, int);					// event handlers


private:
	HWND hListboxL;									// handle to left listbox
	HWND hListboxR;									// handle to right listbox
	HWND hRight;									// handle to > button
	HWND hDblRight;									// handle to >> button
	HWND hLeft;										// handle to < button
	HWND hDblLeft;									// handle to << button
	void appendInAlphaOrder(HWND ListBoxFrom, HWND ListBoxTo);
	int getLength(TCHAR input[])const;
	void copy(TCHAR from[], TCHAR to[]);
	int compare(TCHAR input1[], TCHAR input2[], bool caseSensitive)const;

};

