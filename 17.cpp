// 17.cpp: определяет точку входа для консольного приложения.
//Сортировка методом простой вставки,пирамидальная сортировка, сортировка Хоара
//Определить зависимость времени выполнения алгоритмов от количества элементов 
//для каждого из алгоритмов. 
#include "stdafx.h" 
#include <iostream> 
#include <ctime> 
using namespace std;
//prostaya vstavka
void insertSort(int *A, int size) 
{
	setlocale(LC_ALL, "Russian");
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
	cout << "массив A после вставки сортировки" << endl;
	for (i = 0; i < size; i++)
	{
		if (A[i] != 0)
			cout << A[i] << " ";
	}
	cout << endl;
}
//piramida
void heapify(int a[], int pos, int n)
{
	setlocale(LC_ALL, "Russian");
	int t, tm;
	while (2 * pos + 1 <  n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n  &&  a[2 * pos + 2] >= a[t])
			t = 2 * pos + 2;
		if (a[pos] < a[t])
		{
			tm = a[pos];
			a[pos] = a[t];
			a[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramsort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(a, i, n);
	while (n > 0)
	{
		int tm = a[0];
		a[0] = a[n - 1];
		a[n - 1] = tm;
		n--;
		heapify(a, 0, n);
	}
	cout << endl;
}
//Hoara metod
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j]> brd);
		while (A[++i]< brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);//разбиение массива
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};

void main()
{
	setlocale(LC_ALL, "Russian");
	time_t timer = clock();
	time_t timer1 = clock();
	time_t timer2 = clock();
	using namespace std;
	const int N = 10000;
	int i, sz, A[N];
	cout << "введите размер массва-  ";
	cin >> sz;
	cout << "Массив A: ";
	srand((unsigned)time(NULL)); 
	for (i = 0; i < sz; i++)
	{
		A[i] = rand() % 99;
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
	insertSort(A, sz);
	cout << "Время,затраченное на сортировку простой вставки:" << clock() - timer << endl;
	cout << "----------------------------------------" << endl << endl;
	cout << "Массив A после сортировки Хоара: " << endl;
	sortHoar(A, A[1], A[sz]);
	for (i = 0; i < sz; i++)
		cout << A[i] << " ";
	cout << endl;
	cout << "Время,затраченное на сортировку Хоара:" << clock() - timer1 << endl;
	cout << "----------------------------------------" << endl;
	piramsort(A, sz);
	cout << "Массив A после пирамидальной сортировки: " << endl;
	for (i = 0; i < sz; i++)
		cout << A[i] << " ";
	cout << endl;
 	cout << "Время,затраченное на сортировку пирамидой:" << clock() - timer2 << endl;
	cout << "----------------------------------------" << endl;
	system("pause");
}
