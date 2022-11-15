#include "Graph.h"

Graph::Graph(int n) {
    this->n = n;

    this->adjMatrix = vector<vector<int>>(n);
    for(int q = 0; q < n; q++) {
        this->adjMatrix[q] = vector<int>(n, 0);
    }
}

Graph::Graph(int n, const vector<vector<int>> &v) {
    this->n = n;
    this->adjMatrix = v;
}


void Graph::input() {
    for(int i = 0; i < n; i++) {
        this->adjMatrix.emplace_back(n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
}

void Graph::addEdge(int v1, int v2, int w) {
    this->adjMatrix[v1][v2] = w;
    this->adjMatrix[v2][v1] = w;
}

void Graph::delEdge(int v1, int v2) {
    this->adjMatrix[v1][v2] = 0;
    this->adjMatrix[v2][v1] = 0;
}

int Graph::getEdge(int v1, int v2) {
    return this->adjMatrix[v1][v2];
}

int Graph::getDegree(int v) {
    int result = 0;

    for(auto el: this->adjMatrix[v]) {
        if(el != 0) {
            result++;
        }
    }

    return result;
}

void Graph::print() {
    for(const auto& row: this->adjMatrix){
        for(auto el: row) {
            cout << el << " ";
        }
        cout << endl;
    }
}

bool Graph::isEulerable() {
    for(int v = 0; v < this->n; v++) {
        if(this->getDegree(v) % 2 != 0) {
            return false;
        }
    }

    return true;
}

vector<int> Graph::eulerCycle() {
    if(not this->isEulerable()) {
        cout << "There is no Euler`s cycle" << endl;
        return vector<int>(0);
    }

    vector<int> eulerCycle;

    Graph eulerGraph(this->n, this->adjMatrix);

    stack<int> st;
    st.push(0);

    while(not st.empty()) {
        int v = st.top();

        if(eulerGraph.getDegree(v) == 0) {
            eulerCycle.push_back(v);
            st.pop();
            continue;
        }

        for(int q = 0; q < n; q++) {
            if(eulerGraph.getEdge(v, q) != 0){
                st.push(q);
                eulerGraph.delEdge(v, q);
                break;
            }
        }
    }

    return eulerCycle;
}

Graph Graph::primeGraph() {
    Graph primeGraph(this->n);

    vector<bool> selected(this->n, false);

    selected[0] = true;

    int edges = 0;

    while(edges != this->n - 1) {
        int minStart = -1;
        int minFinish = -1;
        int minEdge = 0;

        for(int curStart = 0; curStart < n; curStart++) {
            if(not selected[curStart]){
                continue;
            }

            for(int curFinish = 0; curFinish < n; curFinish++) {
                if(selected[curFinish] or this->getEdge(curStart, curFinish) == 0) {
                    continue;
                }

                if(minEdge == 0 or this->getEdge(curStart, curFinish) < minEdge) {
                    minEdge = this->getEdge(curStart, curFinish);
                    minStart = curStart;
                    minFinish = curFinish;
                }
            }
        }

        if(minEdge == 0) {
            cout << "Graph is disconnected!" << endl;
            return primeGraph;
        }

        primeGraph.addEdge(minStart, minFinish, minEdge);
        selected[minFinish] = true;
        edges++;
    }

    return primeGraph;
}
