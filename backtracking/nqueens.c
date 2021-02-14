#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct chessboard{
    int board [20][20];
    int n;
};

void makeboard(struct chessboard *x)
{
    int i,j;
    for(i=0;i<x->n;i++)
    {
        for(j=0;j<x->n;j++)
        {
            x->board[i][j] = 0;
        }
    }
    return;
}

int isvalid(struct chessboard *x, int row, int col)
{
    int i,j,flag;
    
    flag = 0;
    for(i=0; i<x->n; i++)     //check in the given row
    {   
        if(x->board[row][i] == 1)
           flag = 1;
    } 
    if(flag  == 1)
    {
        return 0;
    }

    for(i=0; i<x->n; i++)     //check in the given col
    {   
        if(x->board[i][col] == 1)
           flag = 1;
    } 
    if(flag  == 1)
    {
        return 0;
    }

    //check all diagonals

    i = row;   
    j = col;
    while(i <x-> n || j < x->n)
    {
        if(x->board[i][j] == 1)
            flag = 1;
        i++;
        j++;
    }

    if(flag == 1)
    {
        return 0;
    }

    i = row;  
    j = col;
    while(i >0 || j > 0)
    {
        if(x->board[i][j] == 1)
            flag = 1;
        i--;
        j--;
    }

    if(flag == 1)
    {
        return 0;
    }

    i = row;   //check diagonally
    j = col;
    while(i >0 || j < x->n)
    {
        if(x->board[i][j] == 1)
            flag = 1;
        i--;
        j++;
    }

    if(flag == 1)
    {
        return 0;
    }

    i = row;   //check diagonally
    j = col;
    while(i < x->n || j > 0 )
    {
        if(x->board[i][j] == 1)
            flag = 1;
        i++;
        j--;
    }

    if(flag == 1)
    {
        return 0;
    }

    return 1; //after passing all tests it is valid(1)
}

void printboard(struct chessboard *x)
{
    int i,j;
    for(i=0;i<x->n;i++)
    {
        for(j=0;j<x->n;j++)
        {
            printf("%d ",x->board[i][j]);
        }
        printf("\n");
    }
}

bool nqueens(struct chessboard *x,int row)
{
if(row == x->n)
{
    return true;
}
for(int i=0;i<x->n;i++)
{
    if(isvalid(x,row,i))
    {
        x->board[row][i] = 1;

        if(nqueens(x,row+1))
            return true;
        x->board[row][i] = 0;
    }
}

return false;
}


void main()
{

    struct chessboard *x = (struct chessboard *)(malloc(sizeof(struct chessboard)));
    printf("no of queens?\n");
    scanf("%d",&x->n);

    makeboard(x);
    if(nqueens(x,0))
        printboard(x);
    else
        printf("no solution\n");

    return;
}