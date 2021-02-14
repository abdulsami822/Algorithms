#include<stdio.h>
#include<stdlib.h>

void swap(float *i,float *j)
{
    float temp = *i;
    *i = *j;
    *j = temp;
    return; 
}

void bubblesort(float ppw[],float weights[],float profits[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(ppw[j] < ppw[j+1])
            {
                swap(&ppw[j],&ppw[j+1]);
                swap(&weights[j],&weights[j+1]);
                swap(&profits[j],&profits[j+1]);
            }
        }
    }
    return;
}

void fractional_knapsack(float weights[], float profits[], int W, int n,float used[])
{
    float ppw[10];
    int i;
    int bag_weight = 0;
    for(i = 0;i<n;i++)
    {
        ppw[i] = profits[i]/weights[i];
    }
    bubblesort(ppw,weights,profits,n);

    for(i=0;i<n && bag_weight < W;i++)
    {
        if(weights[i]+bag_weight <= W)
        {
            bag_weight += weights[i];
            used[i] = 1;
        }
        else
        {
            float fraction = (W-bag_weight)/weights[i];
            used[i] = fraction;
            bag_weight = W;
        }
    }
    return;

}

void main()
{
    float profits[10],weights[10];
    float used[10];
    float W, total_profit = 0;
    int i,n;

    printf("size?\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        used[i] = 0;
    }

    for(i=0;i<n;i++)
    {
        printf("enter %d item's weight and profit\n",i+1);
        scanf("%f%f",&weights[i],&profits[i]);
    }
    
    printf("capacity?\n");
    scanf("%f",&W);

    fractional_knapsack(weights,profits,W,n,used);
    for(i=0;i<n;i++)
    {
        printf ("%f ",weights[i]);
        printf("%f\n",used[i]);
        total_profit += profits[i]*used[i];
    }
    printf("\n");
    printf("total_profit : %f\n",total_profit);
}