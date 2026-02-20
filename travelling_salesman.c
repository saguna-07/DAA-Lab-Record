#include <stdio.h>
#include <limits.h>
#define N 4
int min_cost = INT_MAX;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int cost(int graph[N][N], int path[])
{
    int total = 0;
    for(int i = 0; i < N - 1; i++)
        total += graph[path[i]][path[i+1]];

    total += graph[path[N-1]][path[0]]; // Return to start
    return total;
}
void tsp(int graph[N][N], int path[], int pos)
{
    if(pos == N)
    {
        int current_cost = cost(graph, path);
        if(current_cost < min_cost)
            min_cost = current_cost;
        return;
    }

    for(int i = pos; i < N; i++)
    {
        swap(&path[pos], &path[i]);
        tsp(graph, path, pos + 1);
        swap(&path[pos], &path[i]); // Backtrack
    }
}
int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int path[N] = {0,1,2,3};
    tsp(graph, path, 1);
    printf("Minimum travelling cost is: %d", min_cost);
    return 0;
}