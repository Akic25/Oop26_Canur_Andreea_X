#include<iostream>
#include"MovieSeries.h"

using namespace std;

MovieSeries::MovieSeries() : count(0) {};

void MovieSeries::init()
{
	count = 0;
}
void MovieSeries::add(Movie* movie)
{
	if (count < 16) {
		movies[count++] = movie;
	}

}
void MovieSeries::print()
{

}
void MovieSeries::sort()
{
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (movies[i]->numberPassedYears(movies[i]->get_year()) > movies[j]->numberPassedYears(movies[j]->get_year()))
			{
				Movie* temp = movies[i];
				movies[i] = movies[j];
				movies[j] = temp;
			}
}
void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << "Name: " << movies[i]->get_name() << endl;;
		cout << "Release Year: " << movies[i]->get_year() << endl;
		cout << "IMDB score: " << movies[i]->get_score() << endl;
		cout << "Length: " << movies[i]->get_length() << endl;
		cout << "Number of Passed Years: " << movies[i]->numberPassedYears(movies[i]->get_year()) << endl;
	}
}