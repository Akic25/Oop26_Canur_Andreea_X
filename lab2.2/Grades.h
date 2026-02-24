#pragma once
#include<string>
class Grades
{
private:
	std::string numestudent;
	float gm;
	float ge;
	float gh;
public:
	Grades();
	void setName(const std::string numestudent);
	bool setGrEn(float ge);
	bool setGrMa(float gm);
	bool setGrHi(float gh);
	std::string getName();
	float getGrEn();
	float getGrMa();
	float getGrHi();
	float getAvgr();

};