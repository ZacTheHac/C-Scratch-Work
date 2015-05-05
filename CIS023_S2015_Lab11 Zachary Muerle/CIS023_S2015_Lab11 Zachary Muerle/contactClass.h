#pragma once
class contactClass
{
public:
	contactClass();//leave this here so I can create the array without having to build data for it
	contactClass(string);
	string getContactString();
	~contactClass();
private:
	nameClass nName;
	addressClass aAddress;
	phoneClass pPhone;
};

