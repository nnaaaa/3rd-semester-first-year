#include <iostream>
#include <vector>
#include <fstream>
#include "sort.h"
#include <time.h>
using namespace std;
struct pairOfHat
{
    int left, right;
};
vector<pairOfHat> findHat(int left, int right, int hat[], int n, int &c_assign, int &c_compare)
{
    vector<pairOfHat> a;
    for (int i = 0 && ++c_assign; ++c_compare && i < n - 1; ++c_assign && ++i)
    {
        for (int j = 0 && ++c_assign; ++c_compare && j < n; ++c_assign && ++j)
            if (++c_compare && left + hat[i] == right + hat[j])
            {
                ++c_assign;
                a.push_back({i, j});
            }
    }
    return a;
}

vector<pairOfHat> findHat2(int left, int right, int hat[], int n, int &c_assign, int &c_compare)
{
    vector<pairOfHat> a;
    sort(hat, 0, n - 1);
    compare(left, right);
    int i = 0, j = n - 1;
    c_compare += 2;
    while (++c_compare && i < j)
    {
        if (++c_compare && (left + hat[i] == right + hat[j]))
        {
            c_assign+=4;
            a.push_back({hat[i],hat[j]});
            i++;
        }
        else if (++c_compare && left + hat[i] < right + hat[j])
            ++c_assign && i++;
        else if (++c_compare && left + hat[i] > right + hat[j])
            ++c_assign && j--;
    }
    return a;
}

int main()
{
    srand(time(NULL));
    ofstream f("hat.txt");
    ofstream f2("hat2.txt");
    for (int i = 0; i <= 500; i += 10)
    {
        int *hat = new int[i];
        for (int j = 0; j < i; ++j)
            hat[j] = rand() % 100;
        int c_assign = 0, c_compare = 0;
        findHat(rand() % 100, rand() % 100, hat, i, c_assign, c_compare);
        f << i << " " << c_assign << " " << c_compare << endl;

        c_assign = 0;
        c_compare = 0;
        findHat2(rand() % 100, rand() % 100, hat, i, c_assign, c_compare);
        f2 << i << " " << c_assign << " " << c_compare << endl;
        delete[] hat;
    }
    f.close();
    system("pause");
    return 0;
}
