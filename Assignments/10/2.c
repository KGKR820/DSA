#include <stdio.h>
#define MAX 100
typedef struct {
    int id, priority, time;
} Task;
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(Task arr[], int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left].priority < arr[smallest].priority)
        smallest = left;
    if (right < n && arr[right].priority < arr[smallest].priority)
        smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void heapSort(Task arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}
void executeTasks(Task tasks[], int n) {
    printf("Execution Order:\n");
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(tasks, n, i);

    Task executed[MAX];
    int count = 0;
    while (n > 0) {
        Task top = tasks[0];
        printf("Task %d (%d, %d)\n", top.id, top.priority, top.time);
        executed[count++] = top;
        tasks[0] = tasks[n - 1];
        n--;
        minHeapify(tasks, n, 0);
    }

    heapSort(executed, count);

    printf("\nSorted by Execution Time:\n");
    for (int i = count - 1; i >= 0; i--)
        printf("Task %d (%d, %d)\n", executed[i].id, executed[i].priority, executed[i].time);
}
int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    Task tasks[MAX];
    printf("Enter tasks (priority execution_time):\n");
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        scanf("%d %d", &tasks[i].priority, &tasks[i].time);
    }
    executeTasks(tasks, n);
    return 0;
}