#include <iostream>
#include "pointer.h"
#include <iomanip>
using namespace std;

int main()
{
    // int *a = new int;
    // *a = 10;
    // int *b = new int;
    // *b = 30;
    // cout << a << "____" << b << endl;
    // swap(a, b);
    // cout << *a;

    // int *array;
    // int n;
    // inputArray(array,n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<array[i]<<" ";
    // }

    // int *a = new int;
    // *a = 10;
    // int *b = new int;
    // *b = 10;
    // int *s=sum(a,b);
    // cout<<*s;
  
    // int *arr;
    // int n;
    // inputArray(arr,n);
    // int *max=findMax(arr,n);
    // cout<<*max;

    // int *arr;
    // int n;
    // inputArray(arr,n);
    // int *dup=copyArray(arr,n);

    // int *arr;
    // int n;
    // inputArray(arr,n);
    // printArray(arr,n);
    // cout<<endl;
    // int length;
    // int sum;
    // int *sub=findLargestTotalSubArray(arr,n,sum,length);
    // printArray(sub,length);

    // int *arr;
    // int n,sum,length;
    // inputArray(arr, n);
    // printArray(arr, n);
    // cout << endl;
    // int *subArr=findLongestAscendingSubArray(arr,n,length);
    // for (int i=0;i<length;++i){
    //     cout<<*(subArr+i)<<" ";
    // }

    // int *arr;
    // int n;
    // inputArray(arr, n);
    // printArray(arr, n);
    // cout<<endl;
    // int *arr2;
    // int n2;
    // inputArray(arr2, n2);
    // printArray(arr2, n2);
    // cout<<endl<<endl;
    // swapArray(arr,arr2,n,n2);
    // printArray(arr,n2);
    // cout<<endl;
    // printArray(arr2,n);

    // int *arr;
    // int n;
    // inputArray(arr, n);
    // printArray(arr, n);
    // cout<<endl;
    // int *arr2;
    // int n2;
    // inputArray(arr2, n2);
    // printArray(arr2, n2);
    // cout<<endl<<endl;
    // int *concate=concatenate2Arrays(arr,arr2,n,n2);
    // int N=n+n2;
    // printArray(concate,N);

    // int *arr=new int[5]{1,4,7,9,17};
    // int n=5;
    // printArray(arr, n);
    // cout << endl;
    // int *arr2=new int[7]{1,2,5,6,8,9,10};
    // int n2=7;
    // printArray(arr2, n2);
    // cout << endl<< endl;
    // int nc = n + n2;
    // int *merge = merge2Arrays(arr, arr2, n, n2,nc);
    // printArray(merge, nc);

    // int *arr;
    // int n;
    // inputArray(arr, n);
    // printArray(arr, n);
    // cout<<endl;
    // int *arr2;
    // int n2;
    // inputArray(arr2, n2);
    // printArray(arr2, n2);
    // cout<<endl<<endl;
    // int **c=generateMatrix2(arr,arr2,n,n2);
    // for (int i=0;i<n;++i){
    //     for (int j=0;j<n2;++j){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int **arr;
    int length=6,width=4;
    generateMatrix(arr,length,width);
    for (int i=0;i<length;++i){
        for (int j=0;j<width;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    int **transpose=transposeMatrix(arr,length,width);
    for (int i=0;i<width;++i){
        for (int j=0;j<length;++j){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

    // int **arr;
    // cout<<"nhap length width arr:";
    // int length,width;
    // cin>>length>>width;
    // generateMatrix(arr,length,width);
    // for (int i=0;i<length;++i){
    //     for (int j=0;j<width;++j){
    //         cout<<arr[i][j]<<setw(2);
    //     }
    //     cout<<endl<<setw(0);
    // }
    // cout<<endl<<endl;
    // int _length,_width;
    // cout<<"nhap length width Subarr:";
    // cin>>_length>>_width;
    // int **clone=findSubmatrix(arr,length,width,_length,_width);
    // for (int i=0;i<_length;++i){
    //     for (int j=0;j<_width;++j){
    //         cout<<clone[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // int **arr;
    // int length=2,width=2;
    // generateMatrix(arr,length,width);
    // for (int i=0;i<length;++i){
    //     for (int j=0;j<width;++j){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;

    // int **arr2;
    // int length2=2,width2=3;
    // generateMatrix(arr2,length2,width2);
    // for (int i=0;i<length2;++i){
    //     for (int j=0;j<width2;++j){
    //         cout<<arr2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    // int **sub = multiple2Matrices(arr, arr2, length, width, length2, width2);
    // for (int i=0;i<length;++i){
    //     for (int j=0;j<width2;++j){
    //         cout<<sub[i][j]<<" ";
    
    //     }
    //     cout<<endl;
    // }

    int *a = new int[5]{1, 4, 7, 8, 10};
    cout << RecursiveBinarySearch(a, 0, 4, 10);
    system("pause");
    return 0;
}
