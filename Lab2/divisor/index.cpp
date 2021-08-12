#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;

int GCD1(int u, int v, int &ca, int &cc)
{
    if (++cc && v == 0)
        return u;
    return GCD1(v, u % v, ++ca, cc);
}

int GCD2(int u, int v, int &ca, int &cc)
{
    int key = 1;
    ca += 2;
    for (int i = 2; ++cc && i <= v; ++ca && ++i)
    {
        cc += 2;
        if (u % i == 0 && v % i == 0)
        {
            key = i;
            ca++;
        }
    }
    return key;
}

int main()
{
    srand(time(NULL));
    ofstream f("gcd.txt");
    ofstream f2("gcd2.txt");
    for (int i = 0; i <= 500; i += 10)
    {
        int u = i + 127;
        int v = i + 10;

        int ca = 0, cc = 0;
        GCD1(u, v, ca, cc);
        f << i << " " << ca << " " << cc << endl;

        ca = 0;
        cc = 0;
        GCD2(u, v, ca, cc);
        f2 << i << " " << ca << " " << cc << endl;
    }

    system("pause");
    return 0;
}
