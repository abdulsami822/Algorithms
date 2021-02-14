#include<stdlib.h>
#include<stdio.h>

struct graph
{
    int array[10][10];
    int n;
};

struct graph * admatrix(struct graph *g)
{
    int i,j;
    for(i = 0;i < g->n;i++)
    {
        for(j = 0;j<g->n;j++)
        {
            g->array[i][j]= -1;
        }
    }
    
    printf("node--1 no node--0\n");
    for(i =0;i<g->n;i++)
    {
        for(j = 0;j<g->n;j++)
        {
            if(g->array[i][j] == -1 && i!=j)
            {
                printf("%d and %d\n",i,j);
                scanf("%d",&g->array[i][j]);
                g->array[j][i] = g->array[i][j];
            }
            if(i==j)
            {
                g->array[i][j] = 0;
            }
        }
    }
    return g;
}

void dfstraverse(struct graph * g,int visited[],int vertex)
{
    int i;
    printf("%d-->",vertex);
    visited[vertex] = 1;
    for(i=0;i<g->n;i++)
    {
        if(visited[i] == 0 && g->array[vertex][i] == 1)
            dfstraverse(g,visited,i);
    }
    return;
}

void dfs(struct graph *g)
{
    int i,visited[10];
    for(i=0;i<g->n;i++)
    {
        visited[i] = 0;
    }
    for(i=0;i<g->n;i++)
    {
        if(visited[i] == 0)
        dfstraverse(g,visited,i);
    }
    printf("\n");
    return;
}

void main()
{
    int n;
    printf("vertices?\n");
    scanf("%d",&n);

    struct graph *g = (struct graph *)(malloc(sizeof(struct graph)));
    g->n = n;

    g = admatrix(g);

    dfs(g);
}