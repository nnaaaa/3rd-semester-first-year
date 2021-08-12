#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
using namespace std;

bool MajorityElement1(int a[10000], int n, int k, int &count_assign, int &count_compare)
{
    int dem = 0;
    ++count_assign;
    ++count_assign;
    for (int i = 0; ++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] == k)
        {

            dem++;
            ++count_assign;
        }
        ++count_assign;
    }
    if (++count_compare && dem >= n / 2)
    {
        return true;
    }
    return false;
}
bool MajorityElement2(int a[10000], int n, int k, int &count_assign, int &count_compare)
{
    ++count_assign;
    for (int i = 0 ;++count_compare && i < n; i++){
        count_assign+=2;
        int count = 0;
        for (int j = i; ++count_compare && j < n; ++count_assign && j++)
        {
            if (++count_compare && a[i] == a[j]){
                ++count_assign;
                count++;
            }
        }
        if ((++count_compare && count >= n/2) && (++count_compare && a[i] == k)){
            return true;
        }
            
    }
    return false;
}


int main()
{
    ofstream f("major.txt");
    ofstream f2("major2.txt");

    for (int n = 0; n <= 500; n += 25)
    {
        int a[10000], k, count_assign = 0, count_compare = 0;
        k = rand() % 10;
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 10;
        }
        MajorityElement1(a, n, k, count_assign, count_compare);
        f <<n<<" "<< count_assign << " "<<count_compare<<endl;

        count_assign = 0;
        count_compare = 0;
        MajorityElement2(a, n, k, count_assign, count_compare);
        f2 <<n<<" "<< count_assign << " "<<count_compare<<endl;
        
        
    }
    f.close();
    f2.close();
    system("pause");
    return 0;
}
