#include<stdio.h>
#include<stdlib.h>

struct queue{
    struct node * array[10];
    int front,rear;
};

struct node{
    int value;
    int array[10];
    struct node *left;
    struct node *right;
};

void swap(struct node **i, struct node **j)
{
    struct node * temp = *i;
    *i = *j;
    *j = temp;
    return;
}

void enqueue(struct queue *q, struct node * node)
{
    (q->rear)++;
    q->array[q->rear] = node;
    return;
}

struct node * dequeue(struct queue *q)
{
    int i=0;
    int index;
    int min =1000;
    for(i=(q->front)+1;i<=q->rear;i++)
    {
        if(q->array[i]->value < min)
        {
            min = q->array[i]->value;
            index = i;
        }
    }
    swap(&q->array[(q->front)+1],&q->array[index]);
    (q->front)++;
    return q->array[q->front];
}



struct node * newnode(int value)
{
    struct node *temp = (struct node *)(malloc(sizeof(struct node)));
    temp->right =NULL;
    temp->left = NULL;
    temp->value = value;
    return temp;
}

void huffmancoding(struct node *root,int code,int array[],int height)
{
    if(height >= 0)                   //if node is not root
        array[height] = code;
    
    if(root->left == NULL && root->right == NULL)   // print code if leaf  
    {
        printf("%d : ",root->value);
        for(int i=0;i<=height;i++)
        {
            printf("%d",array[i]);
        }
        printf("\n");
        return;
    }

    huffmancoding(root->left,0,array,height+1);  //left == 0
    huffmancoding(root->right,1,array,height+1); //right == 1 
    return;
}

void huffmantree(struct queue *q)
{
    struct node * value1 = dequeue(q);
    struct node * value2 = dequeue(q);
    struct node * sum = newnode(value1->value + value2->value);
    sum->left = value1;
    sum->right = value2;
    if(q->front == q->rear)         //there are no elements to make tree //start making codes
    {
        int array[10];
        huffmancoding(sum,-1,array,-1);
        return;
    }
    enqueue(q,sum);
    huffmantree(q);
    return;
}

void main()
{
    int i,size,n,value;
    struct queue *q = (struct queue *)(malloc(sizeof(struct queue)));
    q->front = q->rear = -1;

    printf("size?\n");
    scanf("%d",&n);
    printf("freqs?\n");
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        struct node *temp = newnode(value);
        enqueue(q,temp);
    }
    
    printf("huffman codes are :\n");

    huffmantree(q);
}