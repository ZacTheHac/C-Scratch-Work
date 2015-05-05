#include "stdafx.h"
#include "quadrupedClass.h"


quadrupedClass::quadrupedClass()
{
	iDirection = STOP;
	MoveSpeed = 5;
}


quadrupedClass::~quadrupedClass()
{
}

void quadrupedClass::MoveDirection(int direction){
	iDirection = direction;
}
int quadrupedClass::GetDirection()const{
	return iDirection;
}
