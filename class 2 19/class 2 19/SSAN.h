#pragma once
class SSAN
{
public:
	SSAN();
	SSAN(string);
	~SSAN();
	string getSSAN();
	bool setSSAN(string);
private:
	string SSN;
};

