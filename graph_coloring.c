#include <stdio.h>
#define V 4   // Number of vertices

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[V];

// Check if it's safe to assign color c to vertex v
int isSafe(int v, int c) {
    for(int i = 0; i < V; i++)
        if(graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// Backtracking function
int graphColoring(int m, int v) {
    if(v == V)
        return 1;

    for(int c = 1; c <= m; c++) {
        if(isSafe(v, c)) {
            color[v] = c;

            if(graphColoring(m, v + 1))
                return 1;

            color[v] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    int m = 3; // Number of colors

    if(graphColoring(m, 0)) {
        printf("Solution Exists:\n");
        for(int i = 0; i < V; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    } else {
        printf("No Solution");
    }

    return 0;
}