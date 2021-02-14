#include<stdlib.h>
#include<stdio.h>

struct node{
    int u,v,weight;
};

struct queue{
    struct node * array[10];
    int front,rear;
};

struct graph
{
    int array[10][10];
    int n;
};

void enqueue(struct queue *q,struct node *n)
{
    (q->rear)++;
    q->array[q->rear] = n;
    return;
}

void swap(struct node **i, struct node **j)
{
    struct node *temp = *i;
    *i = *j;
    *j = temp;
    return;
}

struct node * dequeue(struct queue *q)
{
    int i,min=1000,index;
    for(i=(q->front)+1;i<=q->rear;i++)
    {
        if(q->array[i]->weight < min)
        {
            min = q->array[i]->weight;
            index = i;
        }
    }
    swap(&q->array[(q->front)+1] , &q->array[index]);
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

struct node * createnode(int u,int v, int weight)
{
    struct node * n = (struct node *)(malloc(sizeof(struct node)));
    n->u = u;
    n->v = v;
    n->weight = weight;
    return n; 
}

struct queue * makequeue(struct queue *q,struct graph *g)
{
    int i,j;
    for(i=0;i<g->n;i++)
    {
        for(j=i+1;j<g->n;j++)
        {
            if(g->array[i][j])
            {
                enqueue(q,createnode(i,j,g->array[i][j]));
            }
        }
    }
    return q;
}

int find(int set[],int u)
{
    return set[u];
}

void join(int set[],int u,int v,int n) //other name for union
{
    int setu = 0;
    int setv = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(set[i] == set[u])
            setu++;
        else if(set[i] == set[v])
            setv++;
    }

    if(setu >= setv)
    {
        for(i=0;i<n;i++)
        {
            if(set[i] == set[v])
                set[i] = set[u];
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(set[i] == set[u])
                set[i] = set[v];
        }
    }

    return;
}

void kruskals(struct graph *g,struct queue *q)
{   
    int set[10],i;
    for(i=0;i<g->n;i++)
    {
        set[i] = i;
    }

    while(q->front != q->rear)
    {
        struct node *n = dequeue(q);
        if(find(set,n->u) != find(set,n->v))
        {
            printf("%d-->%d\n",n->u,n->v);
            join(set,n->u,n->v,g->n);
        }
    }
    return;
}

void main()
{
    struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
    printf("verteces?\n");
    scanf("%d",&g->n);

    g = admatrix(g);

    struct queue *q = (struct queue *)(malloc(sizeof(struct queue)));
    q->front = q->rear = -1;

    q = makequeue(q,g);

    kruskals(g,q);
    return;
}