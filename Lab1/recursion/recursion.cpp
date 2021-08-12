#include <iostream>
using namespace std;
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
int calTheSum(int n){
    if (n == 0){
        return 0;
    }  
    return n + CalTheSum(n-1);
}

int calTheFactorial(int n){
    if (n == 1){
        return 1;
    }
    return n * CalTheFactorial(n - 1);
}

int exponent(int x,int n){
    if (n==1)
        return x;
    return exponent(x,n-1)*x;
}

int countDigit(int x){
    if (x==0)
        return 0;
    return 1+countDigit(x/10);
}

int countOddDigit(int x){
    if (x==0)
        return 0;
    return countOddDigit(x/10) + ((x%10)%2==0 ? 0 : 1);
}

int countEvenDigit(int x){
    if (x==0)
        return 0;
    return countOddDigit(x/10) + ((x%10)%2==0 ? 1 : 0);
}

int countDivisor(int a,int b,int key=2){
    if ((key==a||key==b))
        return (a%b==0||b%a==0) ? 1 : 0;
    if (a%key==0&&b%key==0)
        return 1+countDivisor(a/key,b/key,key);
    else 
        return countDivisor(a,b,key+1);
}

int GCD(int a,int b){
    if (b==0){
        return a;
    }
    return GCD(b,a%b);
}
int LCM(int a,int b){
    return a*b / GCD(a, b);
}

int reverseValue(int x,int n){
    if (x==0)
        return 0;
    return x%10*pow(10,n-1)+reverseValue(x/10,n-1);
}

int fibo(int x){
    if (x<0)
        return 0;
    if (x==0||x==1)
        return x;
    return fibo(x-1)+fibo(x-2);
}

void permute(string a, int l, int r)  
{  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        for (int i = l; i <= r; i++)  
        {    
            std::swap(a[l], a[i]);  
            permute(a, l+1, r);   
            std::swap(a[l], a[i]);  
        }  
    }  
}  
int main()
{
    permute("abc", 0, 2);
    system("pause");
    return 0;
}