#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v)
{
    printf("%d ", v);
    visited[v] = 1;
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    int queue[MAX], rear = 0, front = 0;
    queue[rear++] = v;
    visited[v] = 1;
    while(rear != front)
    {
        int u = queue[front++];
        printf("%d ", u);
        for(int i = 0; i < n; i++)
        {
            if(graph[u][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int v;
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    printf("Menu\n 1.BFS\n 2.DFS\n ");
    int choice;
    printf("Enter choice\n");
    scanf("%d",&choice);
    if(choice==1){
        bfs(v);
    }
    else{
        dfs(v);
    }
    

    return 0;
}
