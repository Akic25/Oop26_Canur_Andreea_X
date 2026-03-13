#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int width, int height) :width(width), height(height)
{
	a = new char* [height];
		for (int i = 0; i < height; i++)
		{
			a[i] = new char [width];
		}
		Clear();
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			a[i][j] = ' ';
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << a[i][j];
		cout << endl;
	}
	
}

void Canvas::SetPoint(int x, int y, char ch) 
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		a[x][y] = ch;
}

void Canvas::DrawRect(int left, int right, int top, int bottom, char ch)
{
	int i, j;
	for (i = left; i <= right; i++)
	{
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (i = top; i <= bottom; i++)
	{
		SetPoint(right, i, ch);
		SetPoint(left, i, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = bottom; i <= top; i++)
	{
		for (int j = left; j <= right; j++)
			SetPoint(i, j, ch);
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				SetPoint(i, j, ch);
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{   
	int i, j;
	for(int i=0;i<height;i++)
		for(j=0;j<width;j++)
		{ 
	     int d = (i - x) ^ 2 + (j - y) ^ 2;
		 if (d >= ray * (ray - 1) && d <= ray*(ray + 1))
			 SetPoint(i,j , ch);
        }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy; x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
