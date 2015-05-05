#pragma once
using namespace std;
class SSN :
	public string
{
public:
	SSN();
	SSN(string sz_in);
	~SSN();
	string getSSN();
	bool compare(string);
	bool append(string);
private:
	string sz_num;
};

