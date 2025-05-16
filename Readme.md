[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Angel Francisco

## Description
My program successfully runs Prim's Algorithm by virtue of a minHeap and an adjacency matrix. It has two main structures which include: a graph class and a minHeap class. The graph class creates a graph represented as an adjacency matrix (Two-Dimensional Array), and includes several methods that allow a user to add edges, print the graph, and ultimately run Prim's Algorithm. The minHeap class creates a minHeap represented in an array form and includes methods to insert elements (vertices), extract minimum elements, scan for lower cost edges, minHeapify to preserve minHeap properties, check if a vertex exists in the minHeap, and check if the minHeap is empty.  

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log(v))       |
| Extract Min          | O(log(v))       |
| Decrease Key         | O(log(v))       |
| Prim’s MST Overall   | O(v^2 log(v))   |

- **Insert** - Everything runs to O(1) besides the while loop which updates i by (i - 1)/2 for each iteration.

- **Extract Min** - Everything runs to O(1) besides the call to minHeapify() which runs to O(log(n)) itself as it updates the index by either idx * 2 + 1 or idx * 2 + 2 per iteration depending on which child the vertex is being swapped with.

- **Decrease Key** - Everything runs to O(1) besides the while loop which updates i by (i - 1)/2 for each iteration.

- **Prim's Overall** - Nested while loop calls extractMin (O(log(n))) and then enters a for loop that runs to O(n). The while loop itself also runs to O(n). So, in total, Prim's overall run time complexity comes out to O(n^2 log(n)).

## Test Case Description

**Input:** An undirected, weighted, and connected graph consisting of 5 total vertices and 7 edges.

Graph g(5);

g.addEdge(0, 1, 2);

g.addEdge(0, 3, 6);

g.addEdge(1, 2, 3);

g.addEdge(1, 3, 8);

g.addEdge(1, 4, 5);

g.addEdge(2, 4, 7);

g.addEdge(3, 4, 9);

g.primMST();

--

**Output:** The minimum spanning tree for the input graph resulting from Prim's Algorithm along with its total edge cost.

0--1 (Edge Weight: 2)

1--2 (Edge Weight: 3)

0--3 (Edge Weight: 6)

1--4 (Edge Weight: 5)

MST total cost: 16


