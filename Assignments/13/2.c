#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int findMinKey(double key[], bool mstSet[], int n) {
    double min = DBL_MAX;
    int minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    double key[n];          
    bool mstSet[n];         
    double graph[n][n];  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            } else {
                graph[i][j] = calculateDistance(a[i][0], a[i][1], a[j][0], a[j][1]);
            }
        }
    }

   
    for (int i = 0; i < n; i++) {
        key[i] = DBL_MAX;
        mstSet[i] = false;
    }

    key[0] = 0.0;
    double totalWeight = 0.0;

    for (int count = 0; count < n; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    printf("%.2f\n", totalWeight);
    return 0;
}