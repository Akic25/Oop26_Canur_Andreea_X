#include<iostream>
#include "Globals.h"

int CompareMathGrade(Grades s1, Grades s2)
{
	if (s1.getGrMa() > s2.getGrMa())
		return 1;
	else
		if (s1.getGrMa() == s2.getGrMa())
			return 0;
		else
			return -1;

}
int CompareEnglishGrade(Grades s1, Grades s2)
{
	if (s1.getGrEn() > s2.getGrEn())
		return 1;
	else
		if (s1.getGrEn() == s2.getGrEn())
			return 0;
		else
			return -1;

}
int CompareHistoryGrade(Grades s1, Grades s2)
{
	if (s1.getGrHi() > s2.getGrHi())
		return 1;
	else
		if (s1.getGrHi() == s2.getGrHi())
			return 0;
		else
			return -1;

}
int CompareAverageGrade(Grades s1, Grades s2)
{
	if (s1.getAvgr() > s2.getAvgr())
		return 1;
	else
		if (s1.getAvgr() == s2.getAvgr())
			return 0;
		else
			return -1;
}
int CompareStudentName(Grades s1, Grades s2)
{
	if (s1.getName() > s2.getName())
		return 1;
	else
		if (s1.getName() == s2.getName())
			return 0;
		else
			return-1;
}