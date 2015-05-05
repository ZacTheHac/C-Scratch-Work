// class 3 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class divideError{
public:
	divideError::divideError()
	{
		cout << "Divide by 0 error!";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int dividend, divisor;
	
	cout << "Enter dividend: ";
	cin >> dividend;
	cout << endl << endl;

	cout << "Enter divisor: ";
	cin >> divisor;
	cout << endl << endl;

	try{
		if (divisor == 0)
			throw divByZero(divisor);
		else if (divisor<0)
			throw string("Less than 0 error");
		else
			cout << "Quotient = " << dividend / divisor << endl;
			
	}
	catch (int iBad){
		cout << "Invalid Divisor: " << iBad << "\n";
	}
	catch (string sz_err){
		cout << "Invalid divisor: " << sz_err << endl;
	}
	catch (divideError){
	}
	catch (divByZero iDBZ){
		cout << "Divide by 0 error! using " << iDBZ.GetValue() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}

