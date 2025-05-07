#ifndef GRAPH_H
#define GRAPH_H
#include <climits>

using namespace std;

class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix = new int* [vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = inf;
            }
        }
    };

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    };

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    };

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    };

    void primMST() {
        cout << "primMST successfully called on the graph." << endl;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
    int inf = INT_MAX;
};

#endif