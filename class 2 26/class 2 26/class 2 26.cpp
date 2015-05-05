// class 2 26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Base{
public:
	virtual string GetName(){return "Base";}
	int i;
	virtual void setI(int iInt){ i = iInt; }
	virtual int getI(){ return i; }
};
class Derived : public Base{//create a derived class from base
public:
	virtual string GetName(){return "Derived";}
};
class DerivedB : public Derived{
private:
public:
	virtual string GetName(){ return "DerivedB"; }
	virtual void setI(int iInt){i = iInt * 100;}
	virtual int getI(){ return i; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	//Base rBase;
	//cout << "rBase = " << rBase.GetName() << endl;
	//Derived rDerivedA;
	//cout << "rDerived = " << rDerivedA.GetName() << endl;
	DerivedB rDerivedB;
	Base &rBase = rDerivedB;//make rBase a pointer to rDerived
	cout << "rBase = " << rBase.GetName() << endl;//it uses the most derived class function
	cout << "rDerivedB = " << rDerivedB.GetName() << endl;
	rDerivedB.setI(100);
	rBase.setI(200);//doesn't matter, it calls the most derived
	cout << "rBase.i = " << rBase.i << endl;
	cout << "rDerivedB.i = " << rDerivedB.getI() << endl;
	rBase.i = (200);//doesn't matter, it calls the most derived
	rDerivedB.i = (100);
	cout << "rBase.i = " << rBase.i << endl;
	cout << "rDerivedB.i = " << rDerivedB.getI() << endl;
	
	cout << endl;

	system("pause");
	return 0;
}

