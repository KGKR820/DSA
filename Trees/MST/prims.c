#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int vertices) {
    int min = INF, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[5][5], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim's Algorithm
void primMST(int graph[5][5], int vertices) {
    int parent[vertices]; // Array to store the MST
    int key[vertices];    // Key values to pick the minimum weight edge
    int mstSet[vertices]; // To track vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;       // Make key value of the first vertex 0
    parent[0] = -1;   // First node is the root of the MST

    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1; // Add the picked vertex to the MST set

        // Update key values and parent index of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, vertices);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int vertices = 5; // Number of vertices
    primMST(graph, vertices);

    return 0;
}