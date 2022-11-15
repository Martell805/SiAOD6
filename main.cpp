#include "Graph.h"

using namespace std;

void test() {
    Graph(4).print();

    cout << "----------" << endl;

    Graph(4, {
            {0, 1, 2, 1},
            {1, 0, 1, 3},
            {2, 1, 0, 1},
            {1, 3, 1, 0}
    }).print();

    cout << "----------" << endl;

    vector<int> eulerPath = Graph(4, {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0}
    }).eulerCycle();

    for(auto v: eulerPath) {
        cout << v + 1 << " ";
    }
    cout << endl;

    cout << "----------" << endl;

    Graph(4, {
            {0, 1, 2, 2},
            {1, 0, 1, 2},
            {2, 1, 0, 1},
            {2, 2, 1, 0}
    }).primeGraph().print();
}

int main() {
    test();
}
