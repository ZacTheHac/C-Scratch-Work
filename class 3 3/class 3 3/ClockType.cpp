#include "stdafx.h"
#include "ClockType.h"


ClockType::ClockType()
{
}
ClockType::ClockType(int hours, int minutes, int seconds){
	SetTime(hours, minutes, seconds);
}
void ClockType::SetTime(int hours, int minutes, int seconds){
	Hour = hours;
	Minute = minutes;
	Second = seconds;
}
void ClockType::GetTime(int& hours, int& minutes, int& seconds){
	hours = Hour;
	minutes = Minute;
	seconds = Second;
}
string ClockType::DisplayTime(){
	return to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
}
bool ClockType::operator==(const ClockType& clock2) const{
	//using gettime doesnt work. find out why.
	return ((Hour == clock2.Hour) && (Minute == clock2.Minute) && (Second == clock2.Second));
	
}

void ClockType::increment(){
	if (Second < 59){
		Second++;
	}
	else{
		Second = 0;
		if (Minute < 59){
			Minute++;
		}
		else{
			Minute = 0;
			if (Hour < 11){
				Hour++;
			}
			else{
				Hour = 1;
			}
		}
	}
}

void ClockType::operator++(){
	increment();
}

void ClockType::operator<<(string input){
	switch (input[0])
	{
	case 'H':
		Hour = stoi(input.substr(4));
		break;
	case 'M':
		Minute = stoi(input.substr(4));
		break;
	case 'S':
		Second = stoi(input.substr(4));
		break;
	default:
		break;
	}
}

int ClockType::operator[](int value){
	switch (value)
	{
	case 0:
		return Hour;
		break;
	case 1:
		return Minute;
		break;
	case 2:
		return Second;
		break;
	default:
		return INT_MAX;//you screw with my code, it screws back.
		break;
	}
}

ClockType::~ClockType()
{
}
