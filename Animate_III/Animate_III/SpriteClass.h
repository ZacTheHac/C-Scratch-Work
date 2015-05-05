#pragma once
class SpriteClass
{
public:
	SpriteClass();
	~SpriteClass();
	void Draw(HDC);
	void Move();

private:
	HDC hmemdc;
	HBITMAP hbitmap;
	BITMAP bitmap;

	POINT ptLocation;

};

