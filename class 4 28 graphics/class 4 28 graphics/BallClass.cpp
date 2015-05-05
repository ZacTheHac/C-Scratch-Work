#include "stdafx.h"
#include "BallClass.h"


BallClass::BallClass()
{
	fig.Outside.left = 40;
	fig.Outside.top = 40;
	fig.Outside.right = 120;
	fig.Outside.bottom = 120;
	//init coords
	fig.LeftEye.left = 60;
	fig.LeftEye.top = 70;
	fig.LeftEye.right = 66;
	fig.LeftEye.bottom = 75;
	//left Eye
	fig.RightEye.left = 90;
	fig.RightEye.top = 70;
	fig.RightEye.right = 96;
	fig.RightEye.bottom = 75;

	box.Outside.left = 10;
	box.Outside.top = 10;
	box.Outside.right = 500;
	box.Outside.bottom = 400;
	fig.iDirection = STOP;

}


BallClass::~BallClass()
{
}

void BallClass::Draw(HDC hdc){
	HBRUSH brushRed = CreateHatchBrush(HS_DIAGCROSS,RGB(255, 0, 0));
	HBRUSH brushGreen = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH brushBlue = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush;

	FillRect(hdc, &box.Outside, brushGreen);
	FrameRect(hdc, &box.Outside, brushBlue);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));//Blue
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	oldBrush = (HBRUSH)SelectObject(hdc, brushRed);

	//Rectangle(hdc, box.Outside.left, box.Outside.top, box.Outside.right, box.Outside.bottom);

	Ellipse(hdc, fig.Outside.left, fig.Outside.top, fig.Outside.right, fig.Outside.bottom);

	SelectObject(hdc, oldBrush);
	DeleteObject(brushRed);
	//reset brush so eyes fill in white
	Ellipse(hdc, fig.LeftEye.left, fig.LeftEye.top, fig.LeftEye.right, fig.LeftEye.bottom);
	Ellipse(hdc, fig.RightEye.left, fig.RightEye.top, fig.RightEye.right, fig.RightEye.bottom);

	//release line pen
	SelectObject(hdc, oldPen);
	DeleteObject(pen);
}

RECT BallClass::FigSize(){
	RECT rReturn;
	rReturn.bottom = fig.Outside.bottom + 50;
	rReturn.top = fig.Outside.top - 50;
	rReturn.left = fig.Outside.left - 50;
	rReturn.right = fig.Outside.right + 50;
	return rReturn;
}

void BallClass::Move(int iFrameCount){
	int movespeed = iFrameCount;
	if (fig.iDirection == STOP){
		fig.iDirection = RIGHT | DOWN;
	}
	RECT figsize = fig.Outside;
	RECT boxSize = box.Outside;

	if (figsize.right >= boxSize.right){
		fig.iDirection ^= RIGHT;
		fig.iDirection |= LEFT;
	}
	if (figsize.left <= boxSize.left){
		fig.iDirection ^= LEFT;
		fig.iDirection |= RIGHT;
	}
	if (figsize.top <= boxSize.top){
		fig.iDirection ^= UP;
		fig.iDirection |= DOWN;
	}
	if (figsize.bottom >= boxSize.bottom){
		fig.iDirection ^= DOWN;
		fig.iDirection |= UP;
	}


	if (fig.iDirection & RIGHT){//^= is xor
		fig.Outside.left += movespeed;
		fig.Outside.right += movespeed;
		fig.LeftEye.left += movespeed;
		fig.LeftEye.right += movespeed;
		fig.RightEye.left += movespeed;
		fig.RightEye.right += movespeed;

	}
	if (fig.iDirection & LEFT){//^= is xor
		fig.Outside.left -= movespeed;
		fig.Outside.right -= movespeed;
		fig.LeftEye.left -= movespeed;
		fig.LeftEye.right -= movespeed;
		fig.RightEye.left -= movespeed;
		fig.RightEye.right -= movespeed;

	}
	if (fig.iDirection & DOWN){//^= is xor
		fig.Outside.top += movespeed;
		fig.Outside.bottom += movespeed;
		fig.LeftEye.top += movespeed;
		fig.LeftEye.bottom += movespeed;
		fig.RightEye.top += movespeed;
		fig.RightEye.bottom += movespeed;

	}
	if (fig.iDirection & UP){//^= is xor
		fig.Outside.top -= movespeed;
		fig.Outside.bottom -= movespeed;
		fig.LeftEye.top -= movespeed;
		fig.LeftEye.bottom -= movespeed;
		fig.RightEye.top -= movespeed;
		fig.RightEye.bottom -= movespeed;

	}

}
