#include <iostream>
using namespace std;

int partition(int a[], int left, int right)
{
    int pivot = right;
    int i = left - 1;
    for (int j = left; j < right - 1; ++j)
    {
        if (a[j] > a[pivot])
        {
            ++i;
            int temp = a[j];
            a[j] = a[pivot];
            a[pivot] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[pivot];
    a[pivot] = temp;
    return i + 1;
}

void sort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(a, left, right);
    sort(a, left, pivot - 1);
    sort(a, pivot + 1, right);
}

void compare(int &a, int &b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}