#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX];
int visited[MAX], recStack[MAX];
int cycleStart = -1;
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    Node* temp = adjList[node];
    while (temp) {
        int v = temp->vertex;
        if (!visited[v]) {
            if (dfs(v)) {
                return 1;
            }
        } else if (recStack[v]) {
            cycleStart = v;
            return 1;
        }
        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n%d\n", cycleStart);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}