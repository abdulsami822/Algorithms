#include<stdio.h>

void fibonacci(int n)
{
    int array[10],i;
    array[0] = 1;
    array[1] = 1; 
    for(i=2;i<=n;i++)
    {
        array[i] = array[i-1]+array[i-2];
    }

    printf("%d\n",array[n]);
    return;
}

void main()
{
    int n;
    printf("number?\n");
    scanf("%d",&n);
    fibonacci(n);
}