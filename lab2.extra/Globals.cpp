#include "Globals.h"
#include <cstring>

int movie_compare_name(Movie ep4, Movie ep5)
{
	if (ep4.get_name() < ep5.get_name())
		return-1;
	else
		if (ep4.get_name() == ep5.get_name())
			return 0;
		else
			return 1;
}
float movie_compare_score(Movie ep4, Movie ep5)
{
	if (ep4.get_score() < ep5.get_score())
		return -1;
	else
		if (ep4.get_score() == ep5.get_score())
			return 0;
		else
			return 1;
}
int movie_compare_year(Movie ep4, Movie ep5)
{
	if (ep4.get_year() < ep5.get_year())
		return -1;
	else
		if (ep4.get_year() == ep5.get_year())
			return 0;
		else
			return 1;
}
int movie_compare_length(Movie ep4, Movie ep5)
{
	if (ep4.get_length() < ep5.get_length())
		return-1;
	else
		if (ep4.get_length() == ep5.get_length())
			return 0;
		else
			return 1;
}
int movie_compare_passed_years(Movie ep4, Movie ep5)
{
	int y = 2025 - ep4.get_year();
	int w = 2025 - ep5.get_year();
	if (y < w)
		return 1;
	else
		if (y == w)
			return 0;
		else
			return 1;
}