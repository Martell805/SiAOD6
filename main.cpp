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

void testVariant3() {
    Graph graph = Graph(7);

    graph.addEdge(0, 1, 20);
    graph.addEdge(0, 5, 23);
    graph.addEdge(0, 6, 1);
    graph.addEdge(1, 2, 15);
    graph.addEdge(1, 6, 4);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 6, 9);
    graph.addEdge(3, 4, 17);
    graph.addEdge(4, 6, 16);
    graph.addEdge(4, 5, 28);
    graph.addEdge(4, 6, 25);
    graph.addEdge(5, 6, 36);

    graph.print();

    cout << "------------" << endl;

    vector<int> eulerPath = graph.eulerCycle();

    for(auto v: eulerPath) {
        cout << v + 1 << " ";
    }
    cout << endl;

    cout << "----------" << endl;

    graph.primeGraph().print();
}

void task() {
    int n;

    cout << "Enter amount of edges:" << endl;

    cin >> n;

    Graph graph(n);

    int command;
    int vertex, vertex1, vertex2, weight;

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add edge" << endl;
        cout << "2 - get degree of vertex" << endl;
        cout << "3 - print does graph has Euler`s cycle" << endl;
        cout << "4 - get graph Euler`s cycle" << endl;
        cout << "5 - get spanning tree of graph" << endl;
        cout << "6 - input grath`s adjacency matrix" << endl;
        cout << "7 - print graph" << endl;
        cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                cout << "Enter vertexes numbers and weight of edge:" << endl;
                cin >> vertex1 >> vertex2 >> weight;
                graph.addEdge(vertex1 - 1, vertex2 - 2, weight);
                break;
            case 2:
                cout << "Enter vertex number" << endl;
                cin >> vertex;
                cout << "In`s degree is " << graph.getDegree(vertex) << endl;
                break;
            case 3:
                cout << graph.isEulerable() << endl;
                break;
            case 4:
                for(int el: graph.eulerCycle()) {
                    cout << el << " ";
                }
                cout << endl;
                break;
            case 5:
                graph.primeGraph().print();
                break;
            case 6:
                graph.input();
                break;
            case 7:
                graph.print();
                break;
            default:
                cout << "There is no such a command" << endl;
                break;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Choose 0 for test, 1 for variant`s test or 2 for task:" << endl;
    cin >> n;

    switch(n){
        case 0:
            test();
            break;
        case 1:
            testVariant3();
            break;
        case 2:
            task();
            break;
        default:
            cout << "There is no such a task" << endl;
            break;
    }

    return 0;
}
