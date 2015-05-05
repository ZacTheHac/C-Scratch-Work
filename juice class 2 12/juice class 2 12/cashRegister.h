#pragma once
class cashRegister
{
public:
	cashRegister();
	cashRegister(int);
	~cashRegister();
	void acceptAmount(int);
	int getCurrentBalance();
private:
	int cashOnHand;
};

