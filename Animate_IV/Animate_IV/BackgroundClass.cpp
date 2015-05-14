#include "stdafx.h"
#include "BackgroundClass.h"


BackgroundClass::BackgroundClass()
{
	ptLocation = { 0, 0 };
}


BackgroundClass::~BackgroundClass()
{
}

void BackgroundClass::Draw(HINSTANCE hinst, HDC hdc){
	if (hbitmap == nullptr){
		hbitmap = (HBITMAP)LoadImage(hinst, MAKEINTRESOURCE(IDB_BACK), IMAGE_BITMAP, 0, 0, LR_SHARED);
		if (hbitmap == nullptr){
			MessageBox(NULL, _T("BG Bitmap not loaded!"), NULL, NULL);
		}
		else{
			hmemdc = CreateCompatibleDC(hdc);
			SelectObject(hmemdc, hbitmap);
			GetObject(hbitmap, sizeof(BITMAP), &bitmap);
		}
	}
	if (hmemdc != NULL){
		BitBlt(hdc, 
			ptLocation.x, ptLocation.y, 
			bitmap.bmWidth, bitmap.bmHeight, 
			hmemdc, 0, 0, 
			SRCCOPY);

		StretchBlt(hdc, 
			(ptLocation.x + bitmap.bmWidth), ptLocation.y, 
			bitmap.bmWidth, bitmap.bmHeight, 
			hmemdc, 0, 0, 
			bitmap.bmWidth, bitmap.bmHeight, 
			SRCCOPY);
	}
}

void BackgroundClass::Move(){
	if (ptLocation.x < -1 * bitmap.bmWidth)
		ptLocation.x = (ptLocation.x + bitmap.bmWidth);//the proper offset
	else
		ptLocation.x -= 60;

}