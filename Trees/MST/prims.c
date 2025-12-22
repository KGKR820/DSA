#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void print(int parent[],int v,int graph[v][v]){
       for(int i=1;i<v;i++){
         printf("%d - %d %d\n",parent[i],i,graph[i][parent[i]]);
       }
}
int minkey(int key[],bool mstset[],int v){
   int min = INT_MAX;
   int min_index;
   for(int i=0;i<v;i++){
      if(mstset[i] == false && key[i] < min){
         min_index = i;
        min = key[i];
      }
   }
   return min_index;
}
void prim(int v, int graph[v][v]){
     int parent[v];
     int key[v];
     bool mstset[v];
  for(int i=0;i<v;i++){
    key[i] = INT_MAX;
    mstset[i] = false;
  }
    key[0] = 0;
    parent[0] = -1;

    for(int i=0;i<v-1;i++){
        int u = minkey(key,mstset,v);
        mstset[u] = true;

        for(int i=0;i<v;i++){
            if(graph[u][i] && mstset[i] == false && graph[u][i] < key[i]){
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    print(parent,v,graph);

}

int main(){
    int v;
    printf("Enter the no.of vertices in graph -> ");
    scanf("%d",&v);
int graph[v][v];
for(int i=0;i<v;i++){
    printf("Row %d : [",i+1);
    printf("\n");
    for(int j=0;j<v;j++){
        scanf("%d ",&(graph[i][j]));
        
    }
    printf("]\n");
}
printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    prim(v, graph);
    return 0;
}