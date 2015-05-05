// class 2 24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const double Pi = 3.14159;
void fill(int **p, int rowSize, int columnSize){
	for (int row = 0; row < rowSize; row++)
	{
		cout << "Enter " << columnSize << " number(s) for row number " << row << ": ";
		for (int col = 0; col < columnSize; col++){
			cin >> p[row][col];
		}
		cout << endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	//int *i;//create pointer to variable
	//&i = 3;//reference the address. this doesn't actually work;
	double radius;
	double *radiusPtr;//using a double allows us to get the full 64-bit address
	cout << fixed << showpoint << setprecision(2);//from iomanip
	radius = 2.5;//put 2.5 into radius
	radiusPtr = &radius;//grab the address of "radius" and put it into radius ptr's address (* grabs the value, blank grab the address)
	cout << "Line 12: Radius = " << radius << ", area = " << Pi*(*radiusPtr)*(*radiusPtr) << endl;
	cout << "Line 19: Address of RadiusPtr: (&)" << &radiusPtr << endl;//grabs address of radiusPtr
	cout << "Line 19: Address of RadiusPtr: ( )" << radiusPtr << endl;//grabs the address held inside radiusPtr
	cout << "Line 19: Address of RadiusPtr: (*)" << *radiusPtr << endl;//grabs the variable at the address held in radiusPtr
	
	int **board;//2d int array
	int rows;
	int columns;
	rows = 10;
	columns = 5;//don't have to be hardcoded
	board = new int*[rows];//give space for the rows*size of an int
	for (int i = 0; i < rows; i++){
		board[i] = new int[columns];//inside those rows, add columns that are arrays of ints
	}
	fill(board, rows, columns);

	cout << "\n";
	system("pause");
	return 0;
}

