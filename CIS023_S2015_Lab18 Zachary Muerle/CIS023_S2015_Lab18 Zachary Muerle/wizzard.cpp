#include "stdafx.h"
#include "wizzard.h"


wizzard::wizzard(void)
{
}

wizzard::~wizzard(void)
{
}


// Creates the list boxes and buttons, populates the left list box
void wizzard::init(HWND hWnd, HINSTANCE hInst)
{
	// create the left list box
	hListboxL = CreateWindow(_T("LISTBOX"), _T(""),
		WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL | WS_BORDER,
		10, 10, 100, 100,
		hWnd, NULL, hInst, NULL);

	// create the right list box
	hListboxR = CreateWindow(_T("LISTBOX"), _T(""),
		WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL | WS_BORDER,
		155, 10, 100, 100,
		hWnd, NULL, hInst, NULL);

	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("CEPEDA, SIDNEY"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("MARINO, MERLYN"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("SHIELDS, BRYNN"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("TAYLOR, JARED"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("VALVERDE, TIFFANEY"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("WOODS, ANDREA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("BRONSON, ROLANDA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("INGRAM, CARLEE"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("KUHNS, ELISSA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("LANNING, CAROLL"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("LUNDY, GROVER"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("ROSALES, BUSTER"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("SIBLEY, STEPHNIE"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("VANWINKLE, VENESSA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("WILLOUGHBY, ONITA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("CLEMENTE, AISHA"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("JEFFERS, BRIGID"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("MITCHELL, LYNWOOD"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("MOONEY, CECIL"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("NEIL, FLOY"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("OGRADY, YOLANDO"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("OTT, DEWAYNE"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("PRADO, KRISTY"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("SHERMAN, JENISE"));
	SendMessage(hListboxL, LB_ADDSTRING, NULL, (LPARAM)_T("ADAIR, XAVIER"));
	//I had already scripted this together, so I'm using it.




	//original provided code:
	// array of strings to insert (initialize) into the listbox
	/*TCHAR Elements[13][MAX_LOADSTRING] = { _T("doggy"), _T("kitty"), _T("horsy"), _T("rabbit"), _T("piggy"),
	_T("fishy"), _T("calf"), _T("chickin"), _T("ducky"), _T("sheep"), _T("turkey"), _T("goosy"), _T("monkey") };

	// insert the array of strings into the left list box
	int pos;
	for (int i = 0; i < 13; i++)
	pos = (int)SendMessage(hListboxL, LB_ADDSTRING, 0,
	(LPARAM)Elements[i]);*/

	// create the button
	hRight = CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD, 120, 10, 25, 20, hWnd, HMENU(ID_Right), NULL, NULL);
	hDblRight = CreateWindow(TEXT("BUTTON"), TEXT(">>"), WS_VISIBLE | WS_CHILD, 120, 35, 25, 20, hWnd, HMENU(ID_DblRight), NULL, NULL);
	hLeft = CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD, 120, 60, 25, 20, hWnd, HMENU(ID_Left), NULL, NULL);
	hDblLeft = CreateWindow(TEXT("BUTTON"), TEXT("<<"), WS_VISIBLE | WS_CHILD, 120, 85, 25, 20, hWnd, HMENU(ID_DblLeft), NULL, NULL);

}
int wizzard::getLength(TCHAR input[])const{
	int counter = 0;
	TCHAR inp;
	while (true){
		inp = input[counter++];

		if (inp == NULL){
			break;
		}
	}
	return counter;
}
int wizzard::compare(TCHAR input1[], TCHAR input2[], bool caseSensitive)const{//0 means they're equal, -1 means one is bigger, 1 means 2 is bigger
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
	if (equalLength)//it got out of the loop without determining a winner. so they're equal, as long as the length is equal
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
void wizzard::copy(TCHAR from[], TCHAR to[]){
	int length = getLength(from);
	for (int i = 0; i < length; i++)
	{
		to[i] = from[i];
	}
	to[length] = NULL;
}
void wizzard::appendInAlphaOrder(HWND ListBoxFrom, HWND ListBoxTo){
	int lbCount = 0;
	int lbTotalCount = 0;
	TCHAR buff[MAX_LOADSTRING];
	TCHAR currLowest[MAX_LOADSTRING];
	int currLowestIndex = 0;

	lbTotalCount = (int)SendMessage(ListBoxFrom, LB_GETCOUNT, 0, 0);

	for (int j = 0; j < lbTotalCount; j++){
		SendMessage(ListBoxFrom, LB_GETTEXT, 0, (LPARAM)currLowest);//just copy the first one in so I have something to work off
		currLowestIndex = 0;
		lbCount = (int)SendMessage(ListBoxFrom, LB_GETCOUNT, 0, 0);
		for (int i = 0; i < lbCount; i++){
			SendMessage(ListBoxFrom, LB_GETTEXT, i, (LPARAM)buff);
			if (compare(buff,currLowest, false) == 1){//1 means that buff is smaller
				copy(buff, currLowest);
				currLowestIndex = i;
			}
		}
		SendMessage(ListBoxTo, LB_ADDSTRING, 0, (LPARAM)currLowest);
		SendMessage(ListBoxFrom, LB_DELETESTRING, currLowestIndex, NULL);
	}

}

// Event handling code for buttons
//LB messages: https://msdn.microsoft.com/en-us/library/windows/desktop/ff485967(v=vs.85).aspx
void wizzard::ButtonPressed(HWND hWnd, int iCtrl)
{
	int lbItem;							// list box item selected (-1 if none selected)
	int lbCount;//holds the ammount of items in a listbox.
	TCHAR buff[MAX_LOADSTRING];			// holds list box item

	// which button clicked? 
	switch (iCtrl)
	{
	case ID_Right:

		lbItem = (int)SendMessage(hListboxL, LB_GETCURSEL, 0, 0);
		if (lbItem > -1)
		{
			SendMessage(hListboxL, LB_GETTEXT, lbItem, (LPARAM)buff);
			//buff now holds the item we want into the right box, so:
			SendMessage(hListboxR, LB_ADDSTRING, 0, (LPARAM)buff);//add it to the right
			SendMessage(hListboxL, LB_DELETESTRING, lbItem, NULL);//delete it from the left (wparam is the index, lparam means nothing)
			//MessageBox(hWnd, buff,_T("got it"),NULL);
		}
		break;
	case ID_DblRight:
		lbCount = (int)SendMessage(hListboxR, LB_GETCOUNT, 0, 0);
		if (lbCount > 0){
			for (int i = 0; i < lbCount; i++){
				SendMessage(hListboxR, LB_GETTEXT, 0, (LPARAM)buff);
				SendMessage(hListboxL, LB_ADDSTRING, 0, (LPARAM)buff);
				SendMessage(hListboxR, LB_DELETESTRING, 0, NULL);
			}//copy everything to the left. just grab the first one, copy it, and delete as many times as there are items
		}
		appendInAlphaOrder(hListboxL, hListboxR);

		//MessageBox(hWnd, _T(">>"),_T("botton"),NULL);
		break;
	case ID_Left:
		//shamelessly stolen. and slightly modified
		lbItem = (int)SendMessage(hListboxR, LB_GETCURSEL, 0, 0);
		if (lbItem > -1)
		{
			SendMessage(hListboxR, LB_GETTEXT, lbItem, (LPARAM)buff);
			//buff now holds the item we want into the right box, so:
			SendMessage(hListboxL, LB_ADDSTRING, 0, (LPARAM)buff);//add it to the right
			SendMessage(hListboxR, LB_DELETESTRING, lbItem, NULL);//delete it from the left (wparam is the index, lparam means nothing)
			//MessageBox(hWnd, buff,_T("got it"),NULL);
		}
		break;
	case ID_DblLeft:
		lbCount = (int)SendMessage(hListboxL, LB_GETCOUNT, 0, 0);
		for (int i = 0; i < lbCount; i++){
			SendMessage(hListboxL, LB_GETTEXT, 0, (LPARAM)buff);
			SendMessage(hListboxR, LB_ADDSTRING, 0, (LPARAM)buff);
			SendMessage(hListboxL, LB_DELETESTRING, 0, NULL);
			//copy everything to the right
		}
		appendInAlphaOrder(hListboxR, hListboxL);

		//MessageBox(hWnd, _T("<<"),_T("botton"),NULL);
		break;
	default:
		MessageBox(hWnd, _T("Not a button"), _T("botton"), NULL);
		return; // not a button
	}

}
