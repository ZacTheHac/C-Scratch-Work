#pragma once
#define STOP 0	//0000 0000
#define RIGHT 1//0000 0001
#define UP 2//0000 0010
#define LEFT 4//0000 0100
#define DOWN 8//0000 1000
class quadrupedClass
{
public:
	quadrupedClass();
	~quadrupedClass();
	void Move(HWND, int);//window handle so I can check the size, int for frame number
	void Draw(HDC)const;
	RECT RedrawArea()const;
	void MoveDirection(int);
	int GetDirection()const;
	//I found it's usefull as you go on to make functions that don't modify the internal values constant.

private:
	struct Limb{
		POINT Start;
		POINT End;
	};
	RECT Head;
	Limb Back;
	Limb LegFB;//leg: front, back
	Limb LegFF;
	Limb LegBB;//leg: back, back
	Limb LegBF;

	int iDirection;
	int MoveSpeed;
};

