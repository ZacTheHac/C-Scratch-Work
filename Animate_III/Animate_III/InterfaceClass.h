#pragma once
#define MAX_SPRITES 5

class InterfaceClass
{
public:
	InterfaceClass();
	~InterfaceClass();
	void Draw(HDC);
	void CreateSprite();
	void Move(HWND);

private:
	HDC hmemdc;
	HBITMAP hbitmap;
	BITMAP bitmap;

	int iSpriteCount;
	SpriteClass *Sprite[MAX_SPRITES+1];
}