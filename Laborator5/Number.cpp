#include "Number.h"
#pragma warning(disable : 4996)
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int CharToValue(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	return 0;
}

char ValueToChar(int v) {
	if (v >= 0 && v <= 9) return v + '0';
	if (v >= 10 && v <= 15) return v - 10 + 'A';
	return '0';
}

Number::Number(const char* value, int base) {
	if (base >= 2 && base <= 16)
		this->base = base;
	else {
		cout << "Eroare nu exista baza asta ";
		return;
	}
	number = new char[strlen(value) + 1];
	strcpy(number, value);

}

Number::Number(int number) //constructor pentru initializarea cu int 
{
	base = 10; //baza def pt int e 10
	char buffer[50];
	sprintf(buffer, "%d", number);
	this->number = new char[strlen(buffer) + 1];
	strcpy(this->number, buffer);
}
Number::~Number() {
	delete[] number;
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

int Number::GetBase()
{
	return base;
}

void Number::Print() {
	cout << "The number is : ";
	for (int i = 0; i < strlen(number); i++)
		cout << number[i];
	cout << " in base: " << base << endl;
}

bool Number:: operator>(Number& rhs) const {
	if (strlen(this->number) > strlen(rhs.number))
		return true;
	else if (strlen(this->number) < strlen(rhs.number))
		return false;
	else if (strlen(this->number) == strlen(rhs.number)) {
		for (int i = 0; i < strlen(this->number); i++)
			if (this->number[i] - '0' < rhs.number[i] - '0')
				return false;
	}
	return true;
}

bool Number::operator<(Number& rhs) const
{
	if (strlen(this->number) < strlen(rhs.number))
		return true;
	else if (strlen(this->number) > strlen(rhs.number))
		return false;
	else if (strlen(this->number) == strlen(rhs.number))
	{
		for (int i = strlen(this->number); i >= 0; i--)
			if (this->number[i] - '0' > rhs.number[i] - '0')
				return false;
	}
	return true;
}
bool Number::operator==(Number& rhs) const
{
	return (strcmp(number, rhs.number) == 0);
}

void Number::operator--()
{
	for (int i = 1; i < strlen(number); i++)
	{
		number[i - 1] = number[i];
	}
	number[strlen(number) - 1] = '\0';
}
void Number::operator--(int) {
	number[strlen(number) - 1] = '\0';
}
Number::Number(const Number& source) : //copy
	number{ nullptr }
{
	number = new char[strlen(source.number) + 1];
	strcpy(number, source.number);
}
Number::Number(Number&& source) : //move
	number{ source.number } {
	source.number = nullptr;
}

void Number::SwitchBase(int newBase) {
	if (this->base == newBase) return;

	long long valueInDefaultBase = 0;
	long long p = 1;
	int len = strlen(this->number);

	for (int i = len - 1; i >= 0; i--) {
		valueInDefaultBase += (long long)CharToValue(this->number[i]) * p;
		p *= this->base;
	}

	char temp[100]; 
	int index = 0;

	if (valueInDefaultBase == 0) {
		temp[index++] = '0';
	}
	else {
		while (valueInDefaultBase > 0) {
			temp[index++] = ValueToChar(valueInDefaultBase % newBase);
			valueInDefaultBase /= newBase;
		}
	}
	temp[index] = '\0';

	for (int i = 0; i < index / 2; i++) {
		char aux = temp[i];
		temp[i] = temp[index - i - 1];
		temp[index - i - 1] = aux;
	}

	delete[] this->number; 
	this->number = new char[index + 1];
	strcpy(this->number, temp);
	this->base = newBase;
}


char Number::operator[](int index)const {
	if (index >= 0 && index < strlen(number))
		return number[index];
	return '\0';
}
void Number::operator +=(Number& rhs) {
	*this = *this + rhs;
}

Number& Number::operator=(const Number& rhs)
{
	if (this == &rhs) return *this; //daca vrem sa copiem un acelasi obiect doar il returnam
	delete[] number;
	base = rhs.base;
	number = new char[strlen(rhs.number) + 1];
	strcpy(number, rhs.number);
	return *this;
}
Number& Number::operator=(Number&& rhs) {
	if (this == &rhs) return *this;

	delete[] number;
	number = rhs.number;
	base = rhs.base;
	rhs.number = nullptr;
	return *this;
}
Number& Number::operator=(int value) //face din int obiect din Number ca sa il putem utiliza la calcule
{
	*this = Number(value);
	return *this;
}
Number& Number::operator=(const char* value) //inlocuim valoarea din number cu o alta valoare
{
	delete[] number;
	number = new char[strlen(value) + 1];
	strcpy(number, value);
	return *this;
}

Number operator+(const Number& lhs, const Number& rhs) {
	int resultBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;

	long long v1 = 0;
	long long p1 = 1;
	for (int i = strlen(lhs.number) - 1; i >= 0; i--) {
		v1 += (long long)CharToValue(lhs.number[i]) * p1;
		p1 *= lhs.base;
	}

	long long v2 = 0;
	long long p2 = 1;
	for (int i = strlen(rhs.number) - 1; i >= 0; i--) {
		v2 += (long long)CharToValue(rhs.number[i]) * p2;
		p2 *= rhs.base;
	}

	long long sum = v1 + v2;

	Number result(sum);

	result.SwitchBase(resultBase);

	return result;
}

Number operator-(const Number& lhs, const Number& rhs) {
	int resultBase = (lhs.base > rhs.base) ? lhs.base : rhs.base;
	long long v1 = 0;
	long long p1 = 1;
	for (int i = strlen(lhs.number) - 1; i >= 0; i--) {
		v1 += (long long)CharToValue(lhs.number[i]) * p1;
		p1 *= lhs.base;
	}

	long long v2 = 0;
	long long p2 = 1;
	for (int i = strlen(rhs.number) - 1; i >= 0; i--) {
		v2 += (long long)CharToValue(rhs.number[i]) * p2;
		p2 *= rhs.base;
	}
	long long diff = v1 - v2;
	if (diff < 0) diff = 0; 

	Number result(diff);
	result.SwitchBase(resultBase);

	return result;
}