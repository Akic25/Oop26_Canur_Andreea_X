#include<iostream>
#include <cmath>
#include<string>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas canvas(50, 70);
	
	canvas.DrawCircle(15,20,5, '$');
	canvas.Print();
	cout << endl;
	canvas.FillCircle(15,10,5, '$');
	canvas.Print();
	canvas.Clear();

	canvas.DrawRect(12,2,20,6 ,'*');
	canvas.Print();
	cout << endl;
	canvas.FillRect(12,2,20,6, '*');
	canvas.Print();
	canvas.Clear();

	canvas.DrawLine(2, 4, 5, 3, '^');
	canvas.Print();
	cout << endl;
	canvas.Clear();

	return 0;
}