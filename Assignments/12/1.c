#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX];
int visited[MAX];
int n;
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}
void dfs(int node) {
    visited[node] = 1;
    Node* temp = adjList[node];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}
int main() {
    int m;
    printf("No.of Vertices -> ");
    scanf("%d", &n);
    printf("No.of Edges -> ");
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    printf("No.of Components -> %d\n", components);
    for (int i = 1; i <= n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    return 0;
}