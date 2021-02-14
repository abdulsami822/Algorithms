#include<stdio.h>

void printarray(int array[][], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",array[i][j]);
        }
    printf("\n");
    }
}

void main()
{
    int array[10][10],n;
    int i,j;

    printf("n?\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ",&array[i][j]);
        }
    }

    printarray(array,n);

}