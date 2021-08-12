#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int *countWord(vector <string> clone,int &c_assign,int &c_compare){
    vector <string> word;
    int *count = new int[clone.size()];
    c_assign+=2;
    for (int i = 0;++c_compare && i < clone.size();++c_assign && ++i){
        bool repeat = false;
        count[i] = 1;
        c_assign += 2;
        for (int j = 0;++c_compare && j < word.size();++c_assign && ++j){
            if (++c_compare && word[j] == clone[i]){
                count[j]++;
                repeat = true;
                c_assign += 2;
                break;
            }
        }
        if (++c_compare && !repeat){
            ++c_assign;
            word.push_back(clone[i]);
        }
    }
    return count;
}

int *countWord2(vector <string> clone,int &c_assign,int &c_compare){
    for (int i = 0; i < clone.size()-1; ++i){
        for (int j = i + 1; j < clone.size(); ++j){
            if ( clone[i].compare(clone[j]) < 0){
                string temp = clone[i];
                clone[i] = clone[j];
                clone[j] = temp;
            }
        }
    }
    int *count = new int[clone.size()];
    int index = 0;
    c_assign += 3;
    for (int i = 0;++c_compare && i < clone.size()-1;++c_assign && ++i){
        if (++c_compare && clone[i].compare(clone[i+1]) == 0){
            ++c_assign;
            count[index]++;
        }
        else{
            ++c_assign;
            count[index++]++;
        }
    }
    return count;
}

int main()
{
    vector <string> randomArr{"nguyenanh","end","start","connect","out","the","quit"};
    vector<string> a;
    ofstream f("word.txt");
    ofstream f2("word2.txt");

    for (int i = 0;i<=500;i+=10)
    {
        for (int j = 0; j <= i;++j){
            int x = rand() % 7;
            a.push_back(randomArr[x]);
        }
        int c_assign = 0, c_compare = 0;
        int *arr = countWord(a,c_assign,c_compare);
        f << i << " " << c_assign << " " << c_compare << endl;

        c_assign = 0;
        c_compare = 0;
        int *arr2 = countWord2(a,c_assign,c_compare);
        f2 << i << " " << c_assign << " " << c_compare << endl;
    }
    

    system("pause");
    return 0;
}
