#include "NumberList.h"
#include <iostream>

using namespace std;

int main()
{
	NumberList list;
	list.Init();
	list.Add(3);
	list.Add(6);
	list.Add(14);
	list.Add(27);
	list.Add(19);
	list.Add(5);
	list.Sort();
	cout << "Lista dupa sortare este:" << endl;
	list.Print();

	return 0;
}