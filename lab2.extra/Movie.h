#pragma once
#include <iostream>
class Movie {
private:
	char* name;
	int year;
	double score;
	int duration;
public:

	void set_name(const char* name);
	bool set_score(double score);
	bool set_year(int year);
	bool set_length(int duration);
	const char* get_name();
	float get_score();
	int get_year();
	int get_length();
	int numberPassedYears(int releaseYear);
};