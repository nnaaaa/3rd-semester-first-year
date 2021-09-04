#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;
    vector<Edge> edges;

public:
    Graph(string file)
    {
        readFile(file);
        for (const Edge &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
    void readFile(string file)
    {
        ifstream f("input.txt");
        string size;
        getline(f, size);
        adjList.resize(stoi(size));
        string line;
        string element;
        for (int i = 0; i < stoi(size); ++i)
        {
            getline(f, line);
            stringstream ss(line);
            int idx = 0;
            while (getline(ss, element, ' '))
            {
                if (stoi(element))
                {
                    Edge edge{i, idx};
                    edges.push_back(edge);
                }
                idx++;
            }
        }
    }
    void printGraph()
    {
        for (int v = 0; v < adjList.size(); ++v)
        {
            for (int j = 0; j < adjList[v].size() - 1; ++j)
                cout << adjList[v][j] << " <-> ";
            cout << adjList[v][adjList[v].size() - 1] << endl;
        }
    }
};

int main()
{
    Graph graph{"input.txt"};
    graph.printGraph();
    system("pause");
    return 0;
}