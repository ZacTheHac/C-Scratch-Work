#pragma once
//#include "stdafx.h"
class ClockType
{
public:
	ClockType();
	~ClockType();
	ClockType(int hours, int minutes, int seconds);
	void SetTime(int, int, int);
	void GetTime(int&, int&, int&);
	string DisplayTime();
	bool operator==(const ClockType& clock2) const;
	void increment();
	void operator++();
	void operator<<(string input);
	int operator[](int value);
private:
	int Hour, Minute, Second;
};

