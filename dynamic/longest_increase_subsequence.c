#include<stdio.h>

int maximum(int array[],int n)
{
    int i,max=-1;
    for(i=0;i<n;i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

int lis(int array[], int n)
{
    int i,j,lis[n];
    lis[0] = 1;
    for(i=1;i<n;i++)
    {
        lis[i] = 1;
        for(j=0;j<i;j++)
        {
            if(array[i] > array[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
   
    return maximum(lis,n);
}

void main()
{
    int n,i,array[10];
    printf("size?\n");
    scanf("%d",&n);
    printf("numbers?\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("%d\n",lis(array,n));    
}