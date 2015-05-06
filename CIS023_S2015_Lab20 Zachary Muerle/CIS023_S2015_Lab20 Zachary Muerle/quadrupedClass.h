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
	void Move(HWND);//window handle so I can check the size
	void Draw(HDC)const;
	RECT RedrawArea(bool)const;
	void MoveDirection(int,HWND);
	int GetMoveDirection()const;
	//I found it's usefull as you go on to make functions that don't modify the internal values constant.
	void reset();
	void changeSpeed(short);

private:
	struct Limb{
		POINT Start;
		POINT End;
		bool MoveForward;//moving forward or backwards.
	};
	void DrawLine(HDC, POINT, POINT)const;//I was gonna be doing it a ton, Might as well make it a function
	Limb AnimateLimb(Limb);

	RECT Head;
	Limb Back;
	Limb LegFB;//leg: front, back
	Limb LegFF;
	Limb LegBB;//leg: back, back
	Limb LegBF;

	int iDirection;//the direction to travel in
	int iMoveSpeed;//how fast it's going to move
	int iSwingLength;//how far on the x plane can the legs go before reversing direction
	int iLimbLength;//how long the limbs on the animal are
	int iHeadRadius;//how big the head is, and, by extension, how long the dog is.
};

