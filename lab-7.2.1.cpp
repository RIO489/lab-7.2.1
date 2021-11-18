// Lab_7_2_1.cpp
// < Гамаюнов Олександр >
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 5
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n,const int k, const int Low, const int High);
void Print(int** a, const int n,const int k);
int SumMinEven(int** a, const int n,const int k, int minEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int k;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n,k, Low, High);
	Print(a, n,k);
	cout << "Sum Min Element = " << SumMinEven(a, n, k, 0) << endl;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n,const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int SumMinEven(int** a, const int n,const int k, int minEven)
{
	int S = 0;
	minEven = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0) 
		{
			int index = 0;
			for (int j = 0; j < k; j++)
			{
				if (a[i][j] < a[i][index])
					index = j;
			}
			minEven = a[i][index];
				cout << "Min a["<< i << "][" << index << "] = " << minEven << endl;
				S += minEven;
		}
	}
	return S ;
}
