#pragma once
class Die
{
public:
	Die();
	Die(int);
	~Die();
	void roll();
	int getNum();
private:
	int num;
};

