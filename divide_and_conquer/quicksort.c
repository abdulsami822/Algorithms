#include<stdlib.h>
#include<stdio.h>

void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
    return;
}

int partition(int array[], int low, int high)
{
    int j =0;
    int pivot = array[high];
    int i = low-1;
    
    for(j=low;j<high;j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return i+1;
}

void quicksort(int array[],int low,int high)
{
    if(low < high)
    {   
        int pi = partition(array,low,high);
        quicksort(array,low,pi-1);
        quicksort(array,pi+1,high);
    }
}

void printarray(int array[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void main()
{
    int array[10];
    int i,n;

    printf("size?\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    quicksort(array,0,n-1);
    printarray(array,n);
}