#include<stdio.h>

void printarray(int array[], int n)
{
    for(int i= n;i>=1;i--)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return;
}

void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;

    return;
}

void heapify(int array[], int n)
{
    int i,j;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
            if(2*j <= n && array[2*j] < array[j])
            {
                swap(&array[j] , &array[2*j]);
            }
            else if(2*j+1 <= n && array[2*j+1] < array[j])
            {
                swap(&array[j] , &array[2*j+1]);
            }
        }
    }
    return;
}

void delete(int array[], int *num)
{
    swap(&array[1],&array[*num]);

    (*num)--;
    int temp = *num;
    heapify(array,temp);
    return;
}

void heapsort(int array[],int n)
{
    heapify(array,n);
    int size = n;
    while(n>0)
    {
        delete(array,&n);
    }
    printarray(array,size);
    return;
}

void main()
{   
    int i,n,array[10];
    printf("size?\n");
    scanf("%d",&n);

    printf("elements\n");
    for(i=1;i<=n;i++)
        scanf("%d",&array[i]);
    
    heapsort(array,n);

    return;
}