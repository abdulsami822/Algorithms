#include<stdio.h>

int c_m_m(int array[10],int n)
{
    int m[n][n];
    int i,j,k,L,q;

    for(i=1;i<n;i++)
    {
        m[i][i] = 0;
    }

    for(L=2;L<n;L++)
    {
        for(i=1;i<n-L+1;i++)
        {
            j = i+L-1;
            m[i][j] = 1000;

            for(k = i; k < j; k++)
            {
                q = m[i][k] + m[k+1][j] + array[i-1] * array[k] * array[j];

                if(q < m[i][j]) 
                {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n-1];
}

void main()
{
    int array[10];
    int n;


    printf("size?\n");
    scanf("%d",&n);

    printf("eles?\n");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
    
    int r = c_m_m(array,n);

    printf("%d\n",r);
    return;
}
