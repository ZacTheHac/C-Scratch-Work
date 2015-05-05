#include "stdafx.h"
#include "InterfaceClass.h"


InterfaceClass::InterfaceClass()
{
	iSpriteCount = 0;
}


InterfaceClass::~InterfaceClass()
{
	for (int i = 1; i <= iSpriteCount; i++){
		if (Sprite[i] != nullptr)
			delete Sprite[i];
	}
}

void InterfaceClass::Draw(HDC hdc){
	//background
	if (hbitmap == nullptr){
		hbitmap = (HBITMAP)LoadImage(NULL, _T("Back.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		if (hbitmap == NULL){
			MessageBox(NULL, _T("Back.bmp not loaded."), NULL, NULL);
		}
		else{
			hmemdc = CreateCompatibleDC(hdc);
			SelectObject(hmemdc, hbitmap);
			GetObject(hbitmap, sizeof(BITMAP), &bitmap);
		}
	}
	if (hmemdc != nullptr){
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hmemdc, 0, 0, SRCCOPY);
	}

	//sprite
	for(int i = 1; i < iSpriteCount; i++){
		if (Sprite[i] != nullptr)
			Sprite[i]->Draw(hdc);
	}
}

void InterfaceClass::CreateSprite(){
	if (iSpriteCount < MAX_SPRITES){
		if (Sprite[iSpriteCount] != nullptr)
			delete Sprite[iSpriteCount];
		Sprite[++iSpriteCount] = new SpriteClass;
	}
}

void InterfaceClass::Move(HWND hWnd){
	for (int i = 1; i < iSpriteCount;i++)
		Sprite[i]->Move();
	InvalidateRect(hWnd, NULL, TRUE);
}
