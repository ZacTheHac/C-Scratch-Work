#include "stdafx.h"
#include "quadrupedClass.h"


quadrupedClass::quadrupedClass()
{
	reset();
}

void quadrupedClass::reset(){
	iDirection = STOP;
	iMoveSpeed = 5;
	iSwingLength = 20;
	iLimbLength = 40;
	iHeadRadius = 25;

	//head
	Head.top = 0;
	Head.bottom = iHeadRadius*2;
	Head.left = (2*iHeadRadius)+iSwingLength;//back is going to be 3x radius long, and an aditional swinglength for the back leg
	Head.right = Head.left + (2 * iHeadRadius);//This just makes it easier to understand for me.

	//back
		//neck
	Back.Start.x = Head.left + iHeadRadius;
	Back.Start.y = Head.bottom;
		//rear
	Back.End.x = iSwingLength;
	Back.End.y = 2 * iHeadRadius;

	//front legs
		//front
	long yOffset = floor((sqrt(pow((double)iLimbLength, 2) - pow((double)iSwingLength, 2))));//keep forgetting that ^ isn't the exponential in c++
	//y2 + swing2 = limb2. warn of possible loss of data, but there isn't. floor(double) = long
	LegFF.Start = Back.Start;
	LegFF.End.x = Back.Start.x + iSwingLength;
	LegFF.End.y = Back.Start.y + yOffset;
	LegFF.MoveForward = false;
		//back
	LegFB.Start = Back.Start;
	LegFB.End.x = Back.Start.x - iSwingLength;
	LegFB.End.y = Back.Start.y + yOffset;
	LegFB.MoveForward = true;

	//back legs
		//front
	LegBF.Start = Back.End;
	LegBF.End.x = Back.End.x + iSwingLength;
	LegBF.End.y = Back.End.y + yOffset;//y2 + swing2 = limb2
	LegBF.MoveForward = false;//I actually looked up how dogs walk. the left and right sides are in nearly complete sync.
		//back
	LegBB.Start = Back.End;
	LegBB.End.x = Back.End.x - iSwingLength;
	LegBB.End.y = Back.End.y + yOffset;
	LegBB.MoveForward = true;


}

void quadrupedClass::Draw(HDC hdc)const{
	
	/*//DEBUGGING CODE: draw the redraw box. 
	//note: the box is not erased due to how this works (drawing what it would be the previous frame...), 
	//but it's a decent indicator of where the erasing will happen, to be sure it works properly
	HBRUSH brushRed = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));
	FillRect(hdc, &RedrawArea(true), brushRed);
	//END debugging*/


	HPEN penFront = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN penBack = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));//different colors for the legs
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//basic pen is black
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);//store the original pen

	//head
	Ellipse(hdc, Head.left, Head.top, Head.right, Head.bottom);
	//back
	DrawLine(hdc, Back.Start, Back.End);
	//legs
		//front
	SelectObject(hdc, penFront);//change the pen
	DrawLine(hdc, LegFF.Start, LegFF.End);
	DrawLine(hdc, LegBF.Start, LegBF.End);
		//back
	SelectObject(hdc, penBack);//change the pen
	DrawLine(hdc, LegBB.Start, LegBB.End);
	DrawLine(hdc, LegFB.Start, LegFB.End);


	//reset hdc
	SelectObject(hdc, oldPen);
	DeleteObject(pen);
	DeleteObject(penFront);
	DeleteObject(penBack);

}
void quadrupedClass::DrawLine(HDC hdc, POINT start, POINT end)const{
	MoveToEx(hdc, start.x, start.y, NULL);//move the pen to the start position, and I don't want wherever it was
	LineTo(hdc, end.x, end.y);//make a line to the end - technically the last pixel isn't filled, but it's not a huge deal, I'm not doing tons of arithmetic to fill in that last pixel
}

quadrupedClass::~quadrupedClass()
{
}

void quadrupedClass::MoveDirection(int direction, HWND wnd){
	//gonna do some cleanup, so you can't have opposites running at the same time
	if ((direction & DOWN) && (direction & UP)){
		direction ^= DOWN;
		direction ^= UP;
	}
	if ((direction & LEFT) && (direction & RIGHT)){
		direction ^= LEFT;
		direction ^= RIGHT;
	}
	//really, the code would work fine with opposing directions on, but I would prefer to just clean it up a bit.
	if (direction & LEFT){
		Head.left = Back.End.x - iHeadRadius;
		Head.right = Back.End.x + iHeadRadius;
	}
	else if(direction & RIGHT){
		Head.left = Back.Start.x - iHeadRadius;
		Head.right = Back.Start.x + iHeadRadius;
	}
	iDirection = direction;
	InvalidateRect(wnd, NULL, true);//I have to redraw everything or it'll leave some stuff behind if you switch left or right.
}
int quadrupedClass::GetMoveDirection()const{
	return iDirection;
}
void quadrupedClass::Move(HWND Wnd){
	RECT window;
	RECT collision = RedrawArea(true);
	bool needToReverse = false;
	bool bounced = false;
	GetClientRect(Wnd, &window);//get the current window size.
	if (iDirection != STOP){
		if (iDirection & DOWN){
			Head.top += iMoveSpeed;
			Head.bottom += iMoveSpeed;
			Back.Start.y += iMoveSpeed;
			Back.End.y += iMoveSpeed;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.y += iMoveSpeed;
			LegFF.End.y += iMoveSpeed;
			LegBB.End.y += iMoveSpeed;
			LegBF.End.y += iMoveSpeed;
		}
		if (iDirection & UP){
			Head.top -= iMoveSpeed;
			Head.bottom -= iMoveSpeed;
			Back.Start.y -= iMoveSpeed;
			Back.End.y -= iMoveSpeed;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.y -= iMoveSpeed;
			LegFF.End.y -= iMoveSpeed;
			LegBB.End.y -= iMoveSpeed;
			LegBF.End.y -= iMoveSpeed;
		}
		if (iDirection & RIGHT){
			Head.left += iMoveSpeed;
			Head.right += iMoveSpeed;
			Back.Start.x += iMoveSpeed;
			Back.End.x += iMoveSpeed;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.x += iMoveSpeed;
			LegFF.End.x += iMoveSpeed;
			LegBB.End.x += iMoveSpeed;
			LegBF.End.x += iMoveSpeed;
		}
		if (iDirection & LEFT){
			Head.left -= iMoveSpeed;
			Head.right -= iMoveSpeed;
			Back.Start.x -= iMoveSpeed;
			Back.End.x -= iMoveSpeed;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.x -= iMoveSpeed;
			LegFF.End.x -= iMoveSpeed;
			LegBB.End.x -= iMoveSpeed;
			LegBF.End.x -= iMoveSpeed;
		}
		//if changing directions:
		if ((collision.right >= window.right)){
			if (iDirection & RIGHT){
				iDirection ^= RIGHT;//stop going right
				iDirection |= LEFT;//start going left
			}
			
			int difference = collision.right - window.right;
			Head.left -= difference + 1;
			Head.right -= difference + 1;
			Back.Start.x -= difference + 1;
			Back.End.x -= difference + 1;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.x -= difference + 1;
			LegFF.End.x -= difference + 1;
			LegBB.End.x -= difference + 1;
			LegBF.End.x -= difference + 1;
			//set the position to a reasonable one so it can't double-trigger
			needToReverse = true;
			bounced = true;
		}
		if (collision.left <= window.left){
			if (iDirection & LEFT){
				iDirection ^= LEFT;//stop going right
				iDirection |= RIGHT;//start going left
			}

			int difference = window.left - collision.left;
			Head.left += difference + 1;
			Head.right += difference + 1;
			Back.Start.x += difference + 1;
			Back.End.x += difference + 1;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.x += difference + 1;
			LegFF.End.x += difference + 1;
			LegBB.End.x += difference + 1;
			LegBF.End.x += difference + 1;
			needToReverse = true;
			bounced = true;
		}
		if ((collision.bottom >= window.bottom)){
			if (iDirection & DOWN){
				iDirection ^= DOWN;//stop going down
				iDirection |= UP;//start going up
			}

			int difference = collision.bottom - window.bottom;
			Head.top -= difference + 1;
			Head.bottom -= difference + 1;
			Back.Start.y -= difference + 1;
			Back.End.y -= difference + 1;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.y -= difference + 1;
			LegFF.End.y -= difference + 1;
			LegBB.End.y -= difference + 1;
			LegBF.End.y -= difference + 1;
			//set the position to a reasonable one so it can't double-trigger
			bounced = true;
		}
		if ((collision.top <= window.top)){
			if (iDirection & UP){
				iDirection ^= UP;//stop going up
				iDirection |= DOWN;//start going down
			}

			int difference = window.top - collision.top;
			Head.top += difference + 1;
			Head.bottom += difference + 1;
			Back.Start.y += difference + 1;
			Back.End.y += difference + 1;
			LegFB.Start = Back.Start;
			LegFF.Start = Back.Start;
			LegBB.Start = Back.End;
			LegBF.Start = Back.End;
			LegFB.End.y += difference + 1;
			LegFF.End.y += difference + 1;
			LegBB.End.y += difference + 1;
			LegBF.End.y += difference + 1;
			//set the position to a reasonable one so it can't double-trigger
			bounced = true;
		}
		if (needToReverse){
			if (iDirection & LEFT){
				Head.left = Back.End.x - iHeadRadius;
				Head.right = Back.End.x + iHeadRadius;
			}
			else{
				Head.left = Back.Start.x - iHeadRadius;
				Head.right = Back.Start.x + iHeadRadius;
			}
		}
		if (bounced){
			InvalidateRect(Wnd, NULL, true);//just redraw the whole screen. -will probably cause a single loop of recursion, but a single loop won't hurt.
		}

		//do animation
		LegFF = AnimateLimb(LegFF);
		LegFB = AnimateLimb(LegFB);
		LegBF = AnimateLimb(LegBF);
		LegBB = AnimateLimb(LegBB);

	}//this entire block only runs if iDirection != 0

}

quadrupedClass::Limb quadrupedClass::AnimateLimb(quadrupedClass::Limb lim){
	if (lim.MoveForward){
		lim.End.x += iMoveSpeed;
		if (lim.End.x > (lim.Start.x + iSwingLength)){
			lim.End.x = lim.Start.x + iSwingLength;
		}
		int offset = floor((sqrt(pow((double)iLimbLength, 2) - pow((double)(lim.End.x - lim.Start.x), 2))));
		lim.End.y = lim.Start.y + offset;
	}
	else{
		lim.End.x -= iMoveSpeed;
		if (lim.End.x < (lim.Start.x - iSwingLength)){
			lim.End.x = lim.Start.x - iSwingLength;
		}
		int offset = floor((sqrt(pow((double)iLimbLength, 2) - pow((double)(lim.Start.x - lim.End.x), 2))));
		lim.End.y = lim.Start.y + offset;
	}
	if (lim.End.x >= (lim.Start.x + iSwingLength)){
		lim.MoveForward = false;
	}
	else if (lim.End.x <= (lim.Start.x - iSwingLength)){
		lim.MoveForward = true;
	}
	return lim;
}
void quadrupedClass::changeSpeed(short speedChange){
	iMoveSpeed += speedChange;
	if (iMoveSpeed < 0 || iMoveSpeed >= iSwingLength*2){//I know, I'm a killjoy, but it has a few glitches when you send to dog to warp speed
		iMoveSpeed = 5;
	}
}

RECT quadrupedClass::RedrawArea(bool collisionOnly = false)const{
	RECT redrawArea;
	if (Head.left == (Back.End.x - iHeadRadius)){//orig: iDirection & LEFT but if it was facing left but not GOING left, it broke
		redrawArea.right = Back.Start.x + iSwingLength;

		if (iHeadRadius < iSwingLength)
			redrawArea.left = Head.left - iSwingLength;//need to swap these because it's facing the other way
		else
			redrawArea.left = Head.left;
	}
	else{

		if (iHeadRadius < iSwingLength){
			redrawArea.right = Head.right + iSwingLength;
		}
		else{
			redrawArea.right = Head.right;
		}
		redrawArea.left = Back.End.x - iSwingLength;
	}
	redrawArea.top = Head.top;
	redrawArea.bottom = Back.Start.y + iLimbLength;



	if (!collisionOnly){
		if (iDirection & RIGHT){
			redrawArea.left -= iMoveSpeed;
		}
		if (iDirection & LEFT){
			redrawArea.right += iMoveSpeed;
		}
		if (iDirection & UP){
			redrawArea.bottom += iMoveSpeed;
		}
		if (iDirection & DOWN){
			redrawArea.top -= iMoveSpeed;
		}

		//and now compensate for the brush being 2 pixels, not 1
		redrawArea.bottom++;
		redrawArea.left--;
		redrawArea.top--;
		redrawArea.right++;
	}

	return redrawArea;
}