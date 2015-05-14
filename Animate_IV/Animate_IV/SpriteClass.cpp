#include "stdafx.h"
#include "SpriteClass.h"


SpriteClass::SpriteClass()
{
	iFrame = 0;
	hbitmap[0] = nullptr;
	hbitmap[1] = nullptr;
	hbitmap[2] = nullptr;
	hbitmap[3] = nullptr;
}


SpriteClass::~SpriteClass()
{
}


void SpriteClass::Draw(HINSTANCE hinst, HDC hdc){
	int iDIB;//device independant bitmap
	switch (iFrame){
	case 0:
		iDIB = IDB_FRED1; 
		break;
	case 1:
		iDIB = IDB_FRED2; 
		break;
	case 2:iDIB = IDB_FRED3; break;
	case 3:iDIB = IDB_FRED4; break;
	}

	if (hbitmap[iFrame] == nullptr){
		hbitmap[iFrame] = (HBITMAP)LoadImage(hinst, MAKEINTRESOURCE(iDIB), IMAGE_BITMAP, 0, 0, LR_SHARED);
		if (hbitmap[iFrame] == nullptr){
			MessageBox(NULL, _T("Fred Bitmap not loaded!"), NULL, NULL);
		}
		else{
			hmemdc[iFrame] = CreateCompatibleDC(hdc);
			SelectObject(hmemdc[iFrame], hbitmap[iFrame]);
			GetObject(hbitmap[iFrame], sizeof(BITMAP), &bitmap[iFrame]);
		}
	}
	if (hmemdc[iFrame] != NULL){
		BitBlt(hdc,
			300, 350,
			bitmap[iFrame].bmWidth, bitmap[iFrame].bmHeight,
			hmemdc[iFrame], 0, 0,
			SRCCOPY);
	}
}

void SpriteClass::Move(){
	iFrame++;
	if (iFrame > 3)
		iFrame = 0;
}
