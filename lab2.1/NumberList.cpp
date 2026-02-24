#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
	count = 0;
}
bool NumberList::Add(int x)
{
	if (count < 10) {
		numbers[count] = x;
		count = count + 1;
		return true;
	}
	else
		return false;

}
void NumberList::Sort()
{
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (numbers[i] > numbers[j])
			{
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}