#pragma once
class addressClass
{
public:
	addressClass();
	addressClass(string);
	addressClass(string Address, string City, string State, string Zip);
	~addressClass();
	string getFormattedAddress();
private:
	string sAddress;
	string sCity;
	string sState;
	string sZipCode;
};

