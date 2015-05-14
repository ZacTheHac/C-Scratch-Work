#pragma once
class SpriteClass
{
public:
	SpriteClass();
	~SpriteClass();
	void Draw(HINSTANCE, HDC);
	void Move();

private:
	HDC hmemdc[4];
	HBITMAP hbitmap[4];
	BITMAP bitmap[4];
	int iFrame;
};

