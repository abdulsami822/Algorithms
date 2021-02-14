#include<stdio.h>
#include<stdlib.h>

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

void dijikstra(struct graph *g,int source)
{
    int distance[10],visited[10],i,min,vertex,flag = 1;
    for(i=0;i<g->n;i++)
    {   
        visited[i] = 0;
        distance[i] = 1000;
    }

    distance[source] = 0; 
    while(flag)
    {   
        min = 1001;
        for(i=0;i<g->n;i++)
        {
            if(distance[i] < min && visited[i] == 0)
            {
                min = distance[i];
                vertex = i;
            }
        }
        visited[vertex] = 1;

        for(i=0;i<g->n;i++)
        {
            if(visited[i] == 0 && g->array[vertex][i] && distance[i] > distance[vertex]+g->array[vertex][i])
                distance[i] = distance[vertex]+g->array[vertex][i];           
        }
        flag = 0; 
        for(i=0;i<g->n;i++)
        {
            if(visited[i] == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    for(i=0;i<g->n;i++)
    {
        printf("%d ",distance[i]);
    }
    printf("\n");
    return;
}

void main()
{
    int source;
    struct graph *g = (struct graph *)(malloc(sizeof(struct graph)));
    printf("vertices?\n");
    scanf("%d",&g->n);

    g = admatrix(g);

    printf("enter source\n");
    scanf("%d",&source);

    dijikstra(g,source);
}