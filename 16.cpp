// 16.cpp: определяет точку входа для консольного приложения.
//Ввести массив А, в массив В скопировать все элементы массива А, имеющие
//четное значение.Массив В отсортировать по возрастанию, используя алгоритмы
//сортировок: сортировка Шелла, сортировка выбором.

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100;
	int i, sz, A[N], B[10] = {}, k = 0, j; 	int rmn = 0, rmx = 99, LenArr, t = 0, em, sm;
	cout << "Введите размер массива -  ";
	cin >> sz;
	cout << "Массив A:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << A[i] << " ";
	}
	for (i = 0; i < sz; i++)
	{
		if (A[i] % 2 != 0)
		{
			B[k] = A[i];
			k++;
		}
	}
	cout << endl;
	LenArr = sizeof(B) / sizeof(int);
	cout << "Массив B" << endl;
	for (i = 0; i < (LenArr - 1); i++)
	{
		if (B[i] == 0)
		{
			B[i] = B[i - 1];
			t++;
		}
		LenArr = LenArr - t;
		for (i = 0; i < (LenArr - 1); i++)
			if (B[i] != 0)
				cout << B[i] << " ";
	}
	cout << endl;

	{
		for (i = 0; i < (sizeof(B) / sizeof(int)); i++)
		{
			for (j = i + 1, k = i; j < sizeof(B) / sizeof(int); j++)
				if (B[j] > B[k])
					k = j;
			int c = B[k];
			B[k] = B[i];
			B[i] = c;
		}
		cout << "Массив B после сортировки выбора" << endl;
		for (i = 0; i < LenArr; i++)
		{
			if (B[i] != 0)
				cout << B[i] << " ";
		}
	}
	cout << endl;

	{for (i = 1; i < sizeof(B) / sizeof(int); i++)
	{
		t = B[i];
		for (j = i - 1; j >= 0 && B[j] > t; j--)
			B[j + 1] = B[j];
		B[j + 1] = t;
	}
	cout << "Массив B после сортировки Шелла" << endl;
	for (i = 0; i < LenArr; i++)
	{
		if (B[i] != 0)
			cout << B[i] << " ";
	}
	}
	system("Pause");
}