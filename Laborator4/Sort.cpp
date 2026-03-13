#include "Sort.h"
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<stdarg.h>


using namespace std;

//Constructori----------------------

Sort::Sort(int n, int minim, int maxim)
{
	nrElemente = n;

	int range = maxim - minim;
	for (int i = 0; i < nrElemente; i++)
	{
		list[i] = minim + (rand() % range);
	}
}

Sort::Sort() {
	vector<int> defaultVec = { 15, 54, 26, 23, 121, 45, 3 }; //<-intrebat despre implementare
	nrElemente = defaultVec.size();
	list = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++)
		list[i] = defaultVec[i];
}

Sort::Sort(int n, int v[100])
{
	int NrElem = n;

	for (int i = 0; i < NrElem; i++)
	{
		list[i] = v[i];
	}
}
Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		list[i] = va_arg(args, int);
	}
	va_end(args);
}
Sort::Sort(const char s[100])
{
	int lung = strlen(s);
	 nrElemente = 0;
	int i = 0;
	int nrCurent = 0;

	while (i < lung)
	{
		if (s[i]!=',')
		{
			nrCurent = nrCurent * 10 + int(s[i]-'0');
		}
		else
		{
			list[nrElemente] = nrCurent;
			nrElemente++;
			nrCurent = 0;
		}
		i++;
	}
	list[nrElemente] = nrCurent;
	nrElemente++;
}

//Functii-----------------------------


void Sort::InsertSort(bool ascendent = false)
{
	int key;
	for (int i = 1; i < nrElemente; ++i) 
	{
		int key = list[i];
		int j = i - 1;

		while (j >= 0 && list[j] > key) 
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
	ascendent = true;
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortHelper(0, nrElemente - 1, ascendent);
}
void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int m = Partition(low, high, ascendent);
		QuickSortHelper(low, m - 1, ascendent);
		QuickSortHelper(m + 1, high, ascendent);
	}
}
int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = list[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if ((ascendent && list[j] < pivot) || (!ascendent && list[j] > pivot)) {
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[high]);
	return i + 1;
}

void Sort::BubbleSort(bool ascendent = false)
{
	bool swapped;

	for (int i = 0; i < nrElemente - 1; i++) 
	{
		swapped = false;
		for (int j = 0; j < nrElemente - i - 1; j++) 
		{
			if (list[j] > list[j + 1]) 
			{
				swap(list[j], list[j + 1]);
				swapped = true;
			}
		}
         if (!swapped)
			break;
	}

}
int Sort::GetElementFromIndex(int index)
{
	return list[index];
}
int Sort::GetElementsCount()
{
	return nrElemente;
}
void Sort::Print()
{
	for (int i = 0; i < nrElemente; i++)
		cout << list[i] << " ";
	cout << endl;
}