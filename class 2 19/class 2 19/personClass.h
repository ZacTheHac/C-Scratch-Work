#pragma once
class personClass
{
public:
	personClass();
	~personClass();
	void setLastName(string);
	void setFirstName(string);
	bool setSSAN(string);
private:
	string sz_FirstName;
	string sz_LastName;
	SSAN SSN;
};

