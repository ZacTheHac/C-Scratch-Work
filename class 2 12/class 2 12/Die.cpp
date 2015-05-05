#include "stdafx.h"
#include "Die.h"


Die::Die()
{
	cout << "Die constructor run\n";
}

Die::Die(int iInput){
	cout << "Overloaded/nonstandard Constructor run\n";
	num = iInput;
	srand(time(0));
}

void Die::roll(){
	num = rand() % 6 + 1;
}

int Die::getNum(){
	return num;
}


Die::~Die()
{
}
