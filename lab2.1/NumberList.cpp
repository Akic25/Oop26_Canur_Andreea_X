#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
	count = 0;
	capacity = 1;
	numbers = new int[capacity];
}
bool NumberList::Add(int x)
{
	if (count >= capacity)
	{
		int newCapacity = capacity * 2;
		int* temp = new int[newCapacity];

		for (int i = 0; i < count; i++) {
			temp[i] = numbers[i];
		}
		delete[] numbers;
		numbers = temp;
		capacity = newCapacity;
	}

	numbers[count] = x;
	count = count + 1;
	return true;

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

NumberList::~NumberList()
{
	delete[] numbers;
}
