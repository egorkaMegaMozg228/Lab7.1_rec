#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High,int i=0, int j=0);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo =0);
void Sort(int** a, const int rowCount, const int colCount,int i0, int i1);
void Sort1(int** a, const int rowCount, const int colCount,int i0,int i1);
void Change(int** a, const int row1, const int row2, const int colCount, int tmp, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i=0);
void Calc1(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 42;
	int rowCount = 8;
	int colCount = 7;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	PrintRows(a, rowCount, colCount);
	Sort(a, rowCount, colCount,0,0);
	PrintRows(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	PrintRows(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, j + 1, i);
		}
		Create(a, rowCount, colCount, Low, High, j, i+1);
	}
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount,int i0,int i1)
{
	if (i0 < rowCount - 1)
	{
		Sort1(a, rowCount, colCount, i0, i1);
		Sort(a, rowCount, colCount, i0 + 1, i1);
	}
}
void Sort1(int** a, const int rowCount, const int colCount, int i0, int i1)
{
	if (i1 < rowCount - i0 - 1)
	{
		if ((a[i1][0] < a[i1 + 1][0])
			||
			(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] < a[i1 + 1][1])
			||
			(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] == a[i1 + 1][1] &&
				a[i1][2] > a[i1 + 1][2]))
			Change(a, i1, i1 + 1, colCount,0,0);
		Sort1(a, rowCount, colCount, i0, i1 + 1);
	}
}
void Change(int** a, const int row1, const int row2, const int colCount,int tmp,int j)
{
	
	if (j<colCount)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
		Change(a, row1, row2, colCount, tmp, j + 1);
	}
}
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k,int i)
{
	if (i < rowCount)
	{
		Calc1(a, rowCount, colCount, S, k, i, 0);
		Calc(a, rowCount, colCount, S, k, i + 1);
	}

	
}
void Calc1(int** a, const int rowCount, const int colCount, int& S, int& k, int i,int j) 
{
	if (j < colCount)
	{
		if (a[i][j] > 0 || (i % 2 != 0 && j % 2 != 0))
		{
			S += a[i][j];
			k++;
			a[i][j] = 0;
		}
		Calc1(a, rowCount, colCount, S, k, i, j+1);
}
}