// class 2 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*{
		int hr;
		int min;
		int sec;
		ClockType clock;
		clock.setTime(0, 0, 0);
		while (true){
			clock.increment();
			clock.getTime(hr, min, sec);
			cout << "h= " << hr << " m= " << min << " s= " << sec << "\n";
		}
	}*/
	ClockType c1;
	ClockType c2;
	c1.setTime(0, 0, 0);
	c2.setTime(1, 1, 1);

	if (c1.equalClock(c2)){
		cout << "True\n";
	}
	else{
		cout << "False\n";
	}

	system("pause");

	return 0;
}

