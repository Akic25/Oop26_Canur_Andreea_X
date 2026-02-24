#include<iostream>
#include "Grades.h"

Grades::Grades() :gm(0), ge(0), gh(0) {}

void Grades::setName(const std::string name) {
	numestudent = name;

}
std::string Grades::getName() {
	return numestudent;
}
bool Grades::setGrEn(float gre) {
	if (0.0f < gre && gre <= 10.0f)
	{
		ge = gre;
		return true;
	}
	else
		return false;
}
float Grades::getGrEn()
{
	return ge;
}
bool Grades::setGrMa(float grm) {
	if (0.0f < grm && grm <= 10.0f)
	{
		gm = grm;
		return true;
	}
	else
		return false;
}
float Grades::getGrMa()
{
	return gm;
}
bool Grades::setGrHi(float grh) {
	if (0.0f < grh && grh <= 10.0f)
	{
		gh = grh;
		return true;
	}
	else
		return false;
}
float Grades::getGrHi()
{
	return gh;
}
float Grades::getAvgr()
{
	return (ge + gh + gm) / 3.0f;
}