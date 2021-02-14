#include<stdio.h>
#include<stdlib.h>

struct matrix
{
    int matrix1[10][10];
    int matrix2[10][10];
    int resultmatrix[10][10];
};

void strassensmul(struct matrix *m,int start, int n)
{
    if(n == 2)
    {
        int p1 = m->matrix1[0][0] * (m->matrix2[0][1] - m->matrix2[1][1]);
        int p2 = m->matrix2[1][1] * (m->matrix1[0][0] + m->matrix1[0][1]);
        int p3 = m->matrix2[0][0] * (m->matrix1[1][0] + m->matrix1[1][1]);
        int p4 = m->matrix1[1][1] * (m->matrix2[1][0] - m->matrix2[0][0]);
        int p5 = (m->matrix1[0][0] + m->matrix1[1][1]) * (m->matrix2[0][0] + m->matrix2[1][1]);
        int p6 = (m->matrix1[0][1] - m->matrix1[1][1]) * (m->matrix2[1][0] + m->matrix2[1][1]);
        int p7 = (m->matrix1[0][0] - m->matrix1[1][0]) * (m->matrix2[0][0] + m->matrix2[0][1]);

        int c2 = p1 + p2;
        int c3 = p3 + p4;
        int c1 = p4 + p5 + p6 -p2;
        int c4 = p1 - p3 + p5 - p7;


         
    }
    else
    {
        
    }
    
}

void main()
{   
    int i,j;
    int n;

    struct matrix *m = (struct matrix *)(malloc(sizeof(struct matrix)));

    printf("enter size\n");
    scanf("%d",&n);

    printf("2 %d * %d shaped matrices ??\n",n,n);

    printf("matrix-1?\n");
    for(i = 0; i<n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",m->matrix1[i][j]);
        }
        
    }
     printf("matrix-2?\n");
    for(i = 0; i<n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",m->matrix2[i][j]);
        }
        
    }

    strassensmul(m,0,n);

}