#pragma once
class ClockType
{
public:
	ClockType();//constructor
	~ClockType();//destructor

	void setTime(int Hours, int Minutes, int Seconds);//don't need to declare names, only used for intelisense
	void getTime(int& Hours, int& Minutes, int& Seconds) const;
	void increment();
	bool equalClock(const ClockType&) const;

private:
	int hour;
	int minute;
	int second;
};

