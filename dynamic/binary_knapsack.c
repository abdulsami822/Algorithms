#include<stdio.h>

int max(int i, int j)
{
    if(i<j)
    {
        return j;
    }
    return i;
}

void binary_knapsack(int profits[], int weights[], int n, int W)
{
    int array[10][10];
    int i,j;

    for(i=0;i<W+1;i++)
    {
        array[0][i] = 0;
    }

    for(i=0;i<n+1;i++)
    {
        array[i][0] = 0;
    }

    for(i=1;i<n+1;i++)
    {
        for(j=1;j<W+1;j++)
        {
            if(j-weights[i-1] >= 0)
                array[i][j] = array[i-1][j-weights[i-1]] + profits[i-1];

            else
                array[i][j] = array[i-1][j];
        }
    }
    printf("max profit = %d\n",array[n][W]);
    return;
}

void main()
{
    int n,W,i;
    int profits[10],weights[10];
    printf("size?\n");
    scanf("%d",&n);
    printf("weight?\n");
    scanf("%d",&W);

    printf("weights and profits?\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&weights[i],&profits[i]);
    }
    
    binary_knapsack(profits,weights,n,W);
}