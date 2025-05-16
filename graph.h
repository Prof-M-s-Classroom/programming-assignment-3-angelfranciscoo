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
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i][i] = 0;
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
        //Parent and lowest edge cost arrays
        int* p = new int[numVertices];
        int* k = new int[numVertices];

        int cost = 0;

        //Just setting to default vals
        for (int i = 0; i < numVertices; i++) {
            p[i] = -1;
            k[i] = inf;
        }

        //Making it start at 0 everytime -- could ask user for an arbitrary start vertex if I wanted to make it better
        k[0] = 0;

        //Build the actual minheap
        MinHeap minHeap(numVertices);
        for (int i = 0; i < numVertices; i++) {
            minHeap.insert(i, k[i]);
        }

        //Keeps extracting the lowest edge cost and adds it to the final MST -- runs O(n)
        while (!minHeap.isEmpty()) {
            //Runs O(log(n))
            int v = minHeap.extractMin();

            //Runs O(n) per extract
            for (int i = 0; i < numVertices; i++) {
                    int edgeWeight = adjMatrix[v][i];

                    //If there's a lower cost edge that's still in the minheap, add it and then upheapify with decreaseKey to make sure the heap is still accurate
                    if (edgeWeight != inf && minHeap.isInMinHeap(i) && edgeWeight < k[i] && i != v) {
                        k[i] = edgeWeight;
                        p[i] = v;
                        minHeap.decreaseKey(i, edgeWeight);
                    }
            }
        }

        //Output tweaks
        for (int i = 1; i < numVertices; i++) {
            int temp = p[i];
            cout << p[i] << "--" << i << " (Edge Weight: " << adjMatrix[temp][i] << ")" << endl;
            cost += adjMatrix[temp][i];
        }
        cout << "MST total cost: " << cost << endl;

        //Had a memory leak so deleting my initial arrays
        delete[] p;
        delete[] k;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;

    //Created a variable to mimic infinity as we learned it in class for the adjacency matrices
    int inf = INT_MAX;
};

#endif