#pragma once

#define STOP 0	//0000 0000
#define RIGHT 1//0000 0001
#define UP 2//0000 0010
#define LEFT 4//0000 0100
#define DOWN 8//0000 1000
class BallClass
{
public:
	BallClass();
	~BallClass();
	void Draw(HDC);
	void Move(int);
	RECT FigSize();

private:
	typedef struct tagFigure{
		int iDirection;
		RECT Outside;
		RECT LeftEye;
		RECT RightEye;
	} FIGURE;//define type figure. "tagFigure" is basically thrown away
	FIGURE fig;
	FIGURE box;


};

