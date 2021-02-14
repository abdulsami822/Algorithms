#include<stdio.h>
#include<stdlib.h>

void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
    return;
}

void bubblesort(int array[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[j] > array[j+1])
                swap(&array[j],&array[j+1]);
        }
    }
}

void binarysearch()
{
    
}

void main()
{
    int i,n;
    int array[10];
    printf("size?\n");
    scanf("%d",&n);

    printf("numbers?\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    bubblesort(array,n);
}