#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;
#define m 1000000009
#define hashTableSize 2000
struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string file_name)
{
    vector<Company> comList;
    ifstream file(file_name);
    string t;
    getline(file, t);
    while (!file.eof())
    {
        getline(file, t);
        stringstream s(t);
        string name, tax, address;
        getline(s, name, '|');
        getline(s, tax, '|');
        getline(s, address, '|');
        comList.push_back({name, tax, address});
    }
    return comList;
}

long long *initPow()
{
    long long *arr = new long long[20]{1};
    for (int i = 1; i < 20; ++i)
    {
        arr[i] = (arr[i - 1] * 31) % m;
    }
    return arr;
}

long long HashString(string company_name)
{
    long long *pow = initPow();
    long long sum = 0;
    int idx = 0;
    if (company_name.length() > 20)
    {
        for (int i = company_name.length() - 20; i < company_name.length(); ++i)
        {
            sum += (int(company_name[i]) % m + pow[idx++]) % m;
            sum %= m;
        }
    }
    else
    {
        for (int i = 0; i < company_name.length(); ++i)
        {
            sum += (int(company_name[i]) % m + pow[idx++]) % m;
            sum %= m;
        }
    }
    delete[] pow;
    return sum;
}

void Insert(Company *hashTable, Company company)
{
    long long hashed = HashString(company.name);
    int idx = hashed % hashTableSize;
    int step = 0;
    while (hashTable[idx].name != "")
    {
        step++;
        idx = (hashed + step) % hashTableSize;
    }
    hashTable[idx] = company;
}

Company *CreateHashTable(vector<Company> list_company)
{
    Company *hashTable = new Company[hashTableSize];
    for (int i = 0; i < hashTableSize; ++i)
        hashTable[i].name = "";

    for (int i = 0; i < list_company.size(); ++i)
        Insert(hashTable, list_company[i]);

    return hashTable;
}


Company *Search(Company *hashTable, string companyName)
{
    long long hashed = HashString(companyName);
    int idx = hashed % hashTableSize;
    int step = 0;
    
    while (hashTable[idx].name != companyName && step < hashTableSize - 1){
        if (hashTable[idx].name == "")
            return new Company{"","",""};
        idx = (hashed + ++step) % hashTableSize;
    }

    return step < hashTableSize ? hashTable + idx : new Company{"","",""};

}

int main()
{
    vector<Company> a = ReadCompanyList("MST.txt");
    Company *hashTable = CreateHashTable(a);
    Company addcomp{"NguyenAnh", "khtn","16t"};
    Insert(hashTable, addcomp);

    Company *root = Search(hashTable, "NguyenAnh");
    if (root)
        cout << root->address;

    ofstream fileout("output.txt");
    for (int i = 0; i < 2000; i++)
        fileout << i << " " << hashTable[i].name << " " << hashTable[i].profit_tax << " " << hashTable[i].address << endl;
    fileout.close();
    system("pause");
    return 0;
}