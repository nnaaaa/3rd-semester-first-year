#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void printGraph(vector<vector <int>> adjList)
{
    for (int v = 0; v < adjList.size(); ++v)
    {
        for (int j=0;j<adjList[v].size()-1;++j)
           cout << adjList[v][j] << " -> ";
        cout<< adjList[v][adjList[v].size()-1]<<endl;
    }
}

vector<vector <int>> readFile(string file){
    vector<vector <int>> adjList;
    ifstream f("input.txt");
    string size;
    getline(f,size);
    string line;
    string element;
    for (int i=0;i<stoi(size);++i){
        getline(f,line);
        stringstream ss(line);
        
        vector <int> vertice;
        vertice.push_back(i);
        int idx=0;
        while(getline(ss,element,' ')){
            if (stoi(element))
                vertice.push_back(idx);
            idx++;
        }
        adjList.push_back(vertice);
    }
    return adjList;
}

int main()
{
    vector<vector <int>> adjList = readFile("input.txt");
    printGraph(adjList);
    system("pause");
    return 0;
}