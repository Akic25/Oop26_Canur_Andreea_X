#pragma once
class Sort
{
    int* list;
    int  nrElemente;
    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);
public:
    Sort(int n, int minim, int maxim);
    Sort();
    Sort(int n, int v[100]);
    Sort(int n, ...);
    Sort(const char s[100]);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

