#pragma once
class nameClass
{
public:
	nameClass();
	nameClass(string Given, string Family);
	string getNameFamilyGiven();
	~nameClass();
private:
	string sGiven;
	string sFamily;
};

