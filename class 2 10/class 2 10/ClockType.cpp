#include "stdafx.h"
#include "ClockType.h"


ClockType::ClockType()
{
	cout << "ClockType init\n";
}


ClockType::~ClockType()
{
	cout << "ClockType destructed\n";
}

void ClockType::setTime(int hr, int min, int sec){
	hour = hr;
	minute = min;
	second = sec;
}

void ClockType::getTime(int& Hours, int& Minutes, int& Seconds) const{
	Hours = hour;
	Minutes = minute;
	Seconds = second;
}

void ClockType::increment(){
	if (++second >= 60){
		second -= 60;
		if (++minute >= 60){
			minute -= 60;
			if (++hour >= 24){
				hour = 0;
			}
		}
	}
}

bool ClockType::equalClock(const ClockType& clockCompare) const{
	int h, m, s;
	clockCompare.getTime(h, m, s);
	return (second == s && minute == m && hour == h);
	//return false;
}