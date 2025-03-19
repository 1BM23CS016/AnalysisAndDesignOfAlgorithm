#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

void topologicalSort(int n, int graph[MAX][MAX]) {
    int in_degree[MAX] = {0}; 
    int queue[MAX], front=0, rear =-1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear]=i;
        }
    }

    printf("Topological Sort Order: ");
    while (front<=rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int w=0;w<n;w++) {
            if (graph[u][w] == 1) {
                in_degree[w]--;
                if (in_degree[w] == 0) {
                    queue[++rear]=w;
                }
            }
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(n, graph);

    return 0;
}