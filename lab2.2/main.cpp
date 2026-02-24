#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Globals.h"
#include "Grades.h"
using namespace std;

int main()
{
	Grades s1, s2;
	s1.setName("Andrei Vladone Popescu");
	s1.setGrEn(7);
	s1.setGrHi(9);
	s1.setGrMa(8);

	s2.setName("Ariol Popescu");
	s2.setGrEn(4);
	s2.setGrHi(9);
	s2.setGrMa(9.50);

	cout << "Compared by name :" << CompareStudentName(s1, s2) << endl;
	cout << "Compared by Math Grade :" << CompareMathGrade(s1, s2) << endl;
	cout << "Compared by English Grade :" << CompareEnglishGrade(s1, s2) << endl;
	cout << "Compared by History Grade :" << CompareHistoryGrade(s1, s2) << endl;
	cout << "Compared by Average Grade :" << CompareAverageGrade(s1, s2) << endl;

	return 0;
}