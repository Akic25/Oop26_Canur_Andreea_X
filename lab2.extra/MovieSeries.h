#pragma once
#include "Movie.h"

class MovieSeries
{
private:
    Movie* movies[256];

    int count;

public:
    MovieSeries();
    void init();
    void add(Movie* movie);
    void sort();
    void print();
};