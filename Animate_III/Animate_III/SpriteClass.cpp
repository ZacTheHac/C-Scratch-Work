#include "stdafx.h"
#include "SpriteClass.h"


SpriteClass::SpriteClass()
{
	ptLocation.x = 0;
	ptLocation.y = 0;
}


SpriteClass::~SpriteClass()
{
}

void SpriteClass::Draw(HDC hdc){
	if (hbitmap == nullptr){
		hbitmap = (HBITMAP)LoadImage(NULL, _T("sprite1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (hbitmap == NULL){
			MessageBox(NULL, _T("sprite1.bmp not loaded."), NULL, NULL);
		}
		else{
			hmemdc = CreateCompatibleDC(hdc);
			SelectObject(hmemdc, hbitmap);
			GetObject(hbitmap, sizeof(BITMAP), &bitmap);
		}
	}
	if (hmemdc != nullptr){
		BitBlt(hdc, ptLocation.x, ptLocation.y, bitmap.bmWidth, bitmap.bmHeight, hmemdc, 0, 0, SRCCOPY);
	}
}

void SpriteClass::Move(){
	ptLocation.x++;
	ptLocation.y++;
}