#include <stdio.h>
#define MAX 10
int graph[MAX][MAX], visited[MAX];
void vertexCover(int n) {
    int i, j;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] && !visited[i] && !visited[j]) {
                visited[i] = 1;
                visited[j] = 1;
                break;
            }
        }
    }
    printf("Vertex Cover: ");
    for (i = 0; i < n; i++) {
        if (visited[i])
            printf("%d ", i);
    }
}
int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    vertexCover(n);
    return 0;
}