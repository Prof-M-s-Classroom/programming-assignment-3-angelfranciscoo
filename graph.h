#ifndef GRAPH_H
#define GRAPH_H
#include <climits>

#include "heap.h"

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
        int* p = new int[numVertices];
        int* k = new int[numVertices];
        int cost = 0;

        for (int i = 0; i < numVertices; i++) {
            p[i] = -1;
            k[i] = inf;
        }

        k[0] = 0;

        MinHeap minHeap(numVertices);
        for (int i = 0; i < numVertices; i++) {
            minHeap.insert(i, k[i]);
        }

        while (!minHeap.isEmpty()) {
            int v = minHeap.extractMin();

            for (int i = 0; i < numVertices; i++) {
                int edgeWeight = adjMatrix[v][i];
                if (edgeWeight != inf && minHeap.isInMinHeap(i) && edgeWeight < k[i]) {
                    k[i] = edgeWeight;
                    p[i] = v;
                    minHeap.decreaseKey(i, edgeWeight);
                }
            }
        }

        for (int i = 1; i < numVertices; i++) {
            cout << p[i] << "--" << i << " (Edge Weight: " << adjMatrix[i][i] << ")" << endl;
            cost += adjMatrix[i][i];
        }
        cout << "MST total cost: " << cost << endl;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
    int inf = INT_MAX;
};

#endif