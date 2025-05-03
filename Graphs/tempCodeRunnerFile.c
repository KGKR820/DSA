#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
   struct node *next;
}node;
typedef struct Graph{
   int numvertices;
   node **adj;
   int *visited;
}Graph;
node * createNode(int value){
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}
Graph * createGraph(int vertices){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph -> numvertices = vertices;
    graph -> adj = (node**)malloc(vertices * sizeof(node*));
    graph -> visited = (int*)malloc(vertices*sizeof(int));

    for(int i=0;i<vertices;i++){
        graph -> adj[i] = NULL;
        graph -> visited[i] =0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    node *temp = createNode(dest);
    temp -> next = graph -> adj[src];
    graph -> adj[src] = temp;

    temp = createNode(src);
    temp -> next = graph -> adj[dest];
    graph -> adj[dest] = temp;
}
void print(Graph *graph) {
    for (int i = 0; i < graph->numvertices; i++) {
        node *p = graph->adj[i];
        printf("%d: ", i);
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next; 
        }
        printf("NULL\n");
    }
}
void DFS(Graph *graph,int vertex){
    graph -> visited[vertex] =1;
    printf("%d ",vertex);
    node *adjlist = graph -> adj[vertex];
    while(adjlist != NULL){
        int temp = adjlist -> data;
        if(!graph -> visited[temp]){
            DFS(graph,temp);
        }
        adjlist = adjlist -> next;
    }
}
void reset(Graph *graph){
    for(int i=0;i<graph ->numvertices;i++){
        graph -> visited[i] =0;
    }
}
void BFS(Graph *graph,int start){
    int *queue = (int *)malloc(graph -> numvertices*sizeof(int));
    int front = 0;
    int rear =0;
    graph->visited[start] =1;
    queue[rear]=start;
    rear++;
    while(front < rear){
        int current = queue[front];
        front++;
        printf("%d ",current);
       node *adjlist = graph -> adj[current];
       while(adjlist!=NULL){
        int connected = adjlist -> data;
        if(!graph -> visited[connected]){
            graph -> visited[connected]=1;
            queue[rear] = connected;
            rear++;
        }
        adjlist = adjlist -> next;
       }
    }
}

int main(){
    int vertices = 5; 
    Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    print(graph);
    printf("Depth First Search (starting from vertex 0): ");
    DFS(graph,0);
    reset(graph);
    printf("\nBreadth First Search (starting from vertex 0): ");
    BFS(graph,0);
    return 0;
}