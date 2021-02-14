#include<stdlib.h>
#include<stdio.h>

struct graph{
    int array[10][10];
    int n;
};

struct graph * admatrix(struct graph * g)
{
    int i,j;
    for(i=0;i<g->n;i++)
    {
        for(j=0;j<g->n;j++)
        {
            g->array[i][j] = -1;
        }
    }

    for(i=0;i<g->n;i++)
    {
        for(j=0;j<g->n;j++)
        {
            if(g->array[i][j] == -1 && i!=j)
            {
                printf("%d and %d\n",i,j);
                scanf("%d",&g->array[i][j]);
                g->array[j][i] = g->array[i][j]; 
            }
            if(i==j)
            {
                g->array[i][j] =0;
            }
        }
    }
    return g;
}

void printgraph(struct graph *g)
{
    int i,j;
    for(i = 0;i < g->n;i++)
    {
        for(j = 0;j<g->n;j++)
        {
            printf("%d ",g->array[i][j]);
        }
        printf("\n");
    }
}

void prims(struct graph *g)
{
    int i,distance[10],visited[10],flag=1,min,vertex,parent[10];

    for(i=0;i<g->n;i++)
    {
        distance[i] = 1000;
        visited[i] = 0;
    }
    distance[0] = 0;
    
    while(flag)
    {
        min = 1000;
        for(i=0;i<g->n;i++)
        {
            if(distance[i] < min && visited[i] == 0)
            {
                min = distance[i];
                vertex = i;
            }
        }

       // printf("vertex : %d\n",vertex);
        
        visited[vertex] = 1;

        for(i=0;i<g->n;i++)
        {
            if(g->array[vertex][i] && visited[i] == 0 && distance[i] > g->array[vertex][i])
            {
                distance[i] = g->array[vertex][i];
                parent[i] = vertex;
            }
        }

        flag =  0;
        for(i=0;i<g->n;i++)
        {
            if(visited[i] == 0)
            {
                flag = 1;
            }
        }
    }

    for(i=1;i<g->n;i++)
    {
        printf("%d->%d\n",parent[i],i);
    }
    printf("\n");

}

void main()
{
    struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
    printf("size?\n");
    scanf("%d",&g->n);

    g = admatrix(g);
   // printgraph(g);
    prims(g);
}