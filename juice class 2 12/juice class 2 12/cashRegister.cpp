#include "stdafx.h"
#include "cashRegister.h"


cashRegister::cashRegister()
{
}

cashRegister::cashRegister(int cash){
	cashOnHand = cash;
}

void cashRegister::acceptAmount(int accept){
	cashOnHand += accept;
}

int cashRegister::getCurrentBalance(){
	return cashOnHand;
}


cashRegister::~cashRegister()
{
}
