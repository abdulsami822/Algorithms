#include<stdio.h>
#include<stdlib.h>

int search(char string[], char pattern[], int n,int m)
{
    int i,j;
    int flag;
    for(i=0;i<n-m;i++)
    {
        flag = 1;
        for(j=0;j<m;j++)
        {
            if(string[i+j] != pattern[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int n;
    printf("string size?\n");
    scanf("%d",&n);

    char string[n];
    printf("string?\n");
    scanf("%s",&string);

    int m;
    printf("pattern size?\n");
    scanf("%d",&m);

    char pattern[m];
    printf("pattern?\n");
    scanf("%s",&pattern);

    int index = search(string,pattern,n,m);
    if(index == -1)
    {
        printf("not found\n");
    }
    else
    {
        printf("found at %d index of string\n",index);
    }
    
}