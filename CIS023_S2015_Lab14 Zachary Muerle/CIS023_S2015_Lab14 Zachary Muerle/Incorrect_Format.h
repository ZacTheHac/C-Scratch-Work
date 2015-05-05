#pragma once
class Incorrect_Format
{
public:
	Incorrect_Format(string details);
	~Incorrect_Format();
	string what();
private:
	string __Mywhat;
};