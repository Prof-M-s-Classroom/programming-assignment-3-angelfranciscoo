#ifndef HEAP_H
#define HEAP_H
#include <__ranges/elements_view.h>
#include <algorithm>

using namespace std;

class MinHeap {
public:
    MinHeap(int capacity) : capacity(capacity) {
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        size = 0;
    };
    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    };
    void insert(int vertex, int key) {
        heapArray[size] = vertex;
        position[vertex] = size;
        keyArray[vertex] = key;
        size++;

        //Taking care of the array updates during each and every vertex insertion while also upheapifying
        int i = position[vertex];
        while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
            if (keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
                swap(heapArray[(i - 1) / 2], heapArray[i]);
                swap(position[heapArray[(i - 1) / 2]], position[heapArray[i]]);
                i = (i - 1) / 2;
            } else {
                return;
            }
        }
    };

    //Pull lowest cost
    int extractMin() {
        int minVertex = heapArray[0];
        heapArray[0] = heapArray[size - 1]; //Bring last element in heap to the top
        size--;

        position[heapArray[0]] = 0;

        minHeapify(0);

        position[minVertex] = -1;

        return minVertex;
    };

    //Add the lowest cost edge and then upheapify
    void decreaseKey(int vertex, int newKey) {
        keyArray[vertex] = newKey;

        int i = position[vertex];
        while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
            if (keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
                swap(heapArray[(i - 1) / 2], heapArray[i]);
                swap(position[heapArray[(i - 1) / 2]], position[heapArray[i]]);
                i = (i - 1) / 2;
            } else {
                return;
            }
        }
    };
    bool isInMinHeap(int vertex) {
        return position[vertex] < size;
    };
    bool isEmpty() {
        return size == 0;
    };

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    //Challenged myself to create minHeapify recursively instead of iteratively
    void minHeapify(int idx) {
        int i = idx;
        if (idx * 2 + 1 < size && keyArray[heapArray[idx * 2 + 1]] < keyArray[heapArray[i]]) {
            i = idx * 2 + 1;
        }
        if (idx * 2 + 2 < size && keyArray[heapArray[idx * 2 + 2]] < keyArray[heapArray[i]]) {
            i = idx * 2 + 2;
        }
        if (i != idx) {
            swap(heapArray[idx], heapArray[i]);
            swap(position[heapArray[idx]], position[heapArray[i]]);
            minHeapify(i);
        }
    };
};

#endif