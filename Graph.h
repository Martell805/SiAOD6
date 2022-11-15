#ifndef SIAOD6_GRAPH_H
#define SIAOD6_GRAPH_H

#include "vector"
#include "iostream"
#include "stack"

using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adjMatrix;
public:
    explicit Graph(int n);
    Graph(int n, const vector<vector<int>> &v);
public:
    void input();
    void addEdge(int v1, int v2, int w);
    void delEdge(int v1, int v2);
    int getEdge(int v1, int v2);
    int getDegree(int v1);
    void print();
public:
    bool isEulerable();
    vector<int> eulerCycle();
    Graph primeGraph();
};


#endif //SIAOD6_GRAPH_H
