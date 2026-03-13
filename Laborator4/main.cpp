#include <iostream>
#include <vector>
#include <cstring>
#include "Sort.h"
using namespace std;

int main()
{

	// constructor1
	Sort s1(7, 45, 26);
	cout << "Numarul de elemente din s1: " << s1.GetElementsCount() << endl;
	s1.Print();
	s1.BubbleSort();
	cout << "Dupa sortare: ";
	s1.Print();
	cout << endl;

	//constructor2
	Sort s2;
	s2.Print();
	s2.InsertSort(true);
	cout << "Dupa sortare: ";
	s2.Print();
	cout << endl;

	//constructor3
	vector<int> vec = { 42,15,39,8,67,0 };
	Sort s3(6,vec);
	s3.Print();
	s3.QuickSort(false);
	cout << "Dupa sortare: ";
	s3.Print();
	cout << endl;

	//constructor4
	Sort s4(6, 5, 12, 34, 1, 9, 22);
	s4.Print();
	cout << "Elementul de la indexul 4 in s4: " << s4.GetElementFromIndex(4) << endl;
	s4.BubbleSort(false);
	cout << "Dupa sortare: ";
	s4.Print();
	cout << endl;

	//constructor5
	Sort s5("143,86,56,85,12");
	s5.Print();
	s5.InsertSort(true);
	cout << "Dupa sortare: ";
	s5.Print();
	cout << endl;


	return 0;
}