#pragma once
class BackgroundClass
{
public:
	BackgroundClass();
	~BackgroundClass();
	void Draw(HINSTANCE, HDC);
	void Move();

private:
	HDC hmemdc;
	HBITMAP hbitmap;
	BITMAP bitmap;
	POINT ptLocation;
};

