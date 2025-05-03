#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 100

typedef struct {
    int row, col, dist;
} Node;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int isValid(int r, int c, int n, int m, char maze[MAX][MAX], int visited[MAX][MAX]) {
    return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] != '#' && !visited[r][c];
}

int bfs(char maze[MAX][MAX], int n, int m, int start_r, int start_c) {
    Node queue[MAX * MAX];
    bool visited[MAX][MAX] = {0};
    int front = 0, rear = 0;

    queue[rear++] = (Node){start_r, start_c, 0};
    visited[start_r][start_c] = 1;

    while (front < rear) {
        Node curr = queue[front++];

        if (maze[curr.row][curr.col] == 'E' && (curr.row == 0 || curr.row == n-1 || curr.col == 0 || curr.col == m-1)) {
            return curr.dist;
        }

        for (int d = 0; d < 4; d++) {
            int nr = curr.row + dr[d];
            int nc = curr.col + dc[d];

            if (isValid(nr, nc, n, m, maze, visited)) {
                visited[nr][nc] = 1;
                queue[rear++] = (Node){nr, nc, curr.dist + 1};
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char maze[MAX][MAX];
    int start_r = -1, start_c = -1;

    for (int i = 0; i < n; i++) {
        gets(maze[i]);
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
        }
    }

    int steps = bfs(maze, n, m, start_r, start_c);
    printf("%d\n", steps);

    return 0;
}