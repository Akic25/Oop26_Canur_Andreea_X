#include <iostream>
#include <cstring>
#include"Math.h"
using namespace std;

int count;
int xi, yi, zi;
const char a = 'b';
const char b = 'a';
double xd, yd, zd;
int main()
{  
	Math cal;
	cin >> xi >> yi >> zi >> xd >> yd >> zd;
  
	cout << "Pentru numerele de tip int avem: 1 Adunarea " << cal.Add(xi, yi) << " " << cal.Add(xi, yi, zi) << endl;
	cout << "2 Inmnultire:" << cal.Mul(xi, yi) << " " << cal.Mul(xi, yi, zi) << endl;
	cout << "Pentru numerele de double int avem: 1 Adunarea " << cal.Add(xd, yd) << " " << cal.Add(xd, yd, zd) << endl;
	cout << "2 Inmnultire:" << cal.Mul(xd, yd) << " " << cal.Mul(xd, yd, zd) << endl;
	cout << "Vectorul adunat este:" << cal.Add(3, 2, 3, 4)  << endl;
	cout << "Constantele char Lipite sunt :" << cal.Add(a, b) << endl;

	return 0;
}
