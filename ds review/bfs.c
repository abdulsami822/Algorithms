#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int array[10][10];
    int n;
};


struct queue
{
  int array[10],front,rear;
};

void enqueue(struct queue *q, int value)
{
    (q->rear)++;
    q->array[q->rear] = value;
    return; 
}

int dequeue(struct queue *q)
{
    (q->front)++;
    return q->array[q->front]; 
}

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


void bfs(struct graph *g)
{
    int visited[10],i,vertex;
    for(i=0;i<g->n;i++)
    {
        visited[i] = 0;
    }

    struct queue *q = (struct queue *)(malloc(sizeof(struct queue)));
    q->front = q->rear = -1; 

    visited[0] = 1;
    enqueue(q,0);

    while(q->front != q->rear)
    {
        vertex = dequeue(q);
        printf("%d-->",vertex);
        for(i = 0;i<g->n;i++)
        {
            if(g->array[vertex][i]==1 && visited[i]==0)
            {
                visited[i] = 1;
                enqueue(q,i);
            }
        }
    }
    return;
}

void main()
{
    int i,j,n;
    printf("number of vertices??\n");
    scanf("%d",&n);

    struct graph *g = (struct graph *)(malloc(sizeof(struct graph)));
    g->n = n;

    g = admatrix(g);
    printgraph(g);
    //scanf("%d",&i);
    bfs(g);
    return;
}