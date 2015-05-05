// CIS023_S2015_Lab17 Zachary Muerle.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CIS023_S2015_Lab17 Zachary Muerle.h"
#include "TCstring.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

MyStack<bool> getBianary(int baseTen){
	MyStack<bool> baseTwo;//a stack of bools, as bools only take up 1 byte, just like bianary should.
	int length = 0;//how many bianary digits we need to hold the value
	//okay, an int can hold up to 2^32, which means 32 digits. but, that includes positive and negative, so only 31 digits needed for a signed, but positive, int.
	for (int i = 1; i < 32; i++)
	{
		if (pow(2, i) >= baseTen){
			length = i;
			break;
		}
	}
	for (int i = 0; i < length; i++){
		baseTwo.push((baseTen % 2) == 1);//remainder gives us the bianary. it was complaining about performance when I just shoved it straight in, so now it has a comparison
		baseTen = baseTen / 2;//do integer division to reduce the value
	}
	for (int i = 0; i < 31 - length; i++)
	{
		baseTwo.push(false);
	}//fill the extra space with 0
	return baseTwo;
}

INT_PTR CALLBACK BianaryConvert(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK){
			int input = 0;
			MyStack<bool> myStack;
			TCHAR tcOutputBianary[32];
			try{
				TCHAR tcInput[MAX_LOADSTRING];
				GetDlgItemText(hDlg, IDC_EDIT1, tcInput, MAX_LOADSTRING);
				input = stoi(tcInput);
				if (input < 0){
					throw out_of_range("The input must be positive.");
				}
				myStack = getBianary(input);
				bool val;
				for (int i = 0; i < 31; i++){
					val = myStack.top();
					if (val){
						tcOutputBianary[i] = '1';
					}
					else{
						tcOutputBianary[i] = '0';
					}
					myStack.pop();
				}
				tcOutputBianary[31] = NULL;
				wstring msg = tcOutputBianary;

				TCstring messageforu;
				messageforu += "hi, loser. the value of ";
				messageforu += tcInput;
				messageforu += " In bianary is:";
				messageforu += tcOutputBianary;

				SetDlgItemText(hDlg, IDC_BIANOUTPUT, messageforu.getLPCWSTR());//msg.c_str()
			}
			catch (invalid_argument){
				MessageBeep(1);
				MessageBox(hDlg, _T("That wasn't a number"), _T("Error"), 1);
			}
			catch (out_of_range){
				MessageBeep(1);
				MessageBox(hDlg, _T("The Input must be a positive integer. (between 0 and 2147483647, inclusive)"), _T("Error"), 1);
			}
			return (INT_PTR)TRUE;
		}
		else if(LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CIS023_S2015_LAB17ZACHARYMUERLE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIS023_S2015_LAB17ZACHARYMUERLE));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIS023_S2015_LAB17ZACHARYMUERLE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CIS023_S2015_LAB17ZACHARYMUERLE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case ID_FILE_BIANARYCONVERT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_BCONVERT), hWnd, BianaryConvert);
			break;//I kinda want to leave this out, so that once the dialog is closed, it closes everything.
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
