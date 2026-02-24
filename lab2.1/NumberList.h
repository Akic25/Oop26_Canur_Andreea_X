#pragma once
class NumberList
{
    int* numbers;
    int count;
    int capacity;
public:
    void Init();        
    bool Add(int x);      
    void Sort();       
    void Print();
};

