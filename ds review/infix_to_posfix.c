#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
    char array[100];
    int top;    
}*stak;

int weight(char a)
{
    if(a == '*' && a == '/')
        return 2;
    else if(a == '+' && a == '-')
        return 1;
}

void pop(char array[],int *top)
{   
    printf("%c",array[*top]);
    (*top)--;
    return;
}

void push(char array[], int *top, char operation)
{
    if(*top == -1 || operation == '(')
    {
        (*top)++;
        array[*top] = operation;
    }

    else if(operation == ')')
    {
        while(array[*top] != '(')
            pop(array,top);
        (*top)--;
    }  
    else
    {
        while(*top != -1 &&  weight(array[*top]) >= weight(operation))
        {
            pop(array,top);
        }
        (*top)++;
        array[*top] = operation;
    }
    return;
}


void main()
{
    stak = (struct stack *)malloc(sizeof(struct stack));
    stak->top=-1;
    char expression[20];
    int i;
    printf("expression?\n");
    gets(expression);
    int len = strlen(expression);

    for(i = 0;i<len;i++)
    {
        if(expression[i] > 'a' && expression[i] < 'z' || expression[i] > 'A' && expression[i] > 'Z')
        {
            printf("%c",expression[i]);
        }
        else
        {
            push(stak->array,&stak->top,expression[i]);
        }
    }
    if(stak->top!=-1)
        while(stak->top!=-1)
        {
            pop(stak->array,&stak->top);
        }
   // printf("top = %d\n",stak->top);
    printf("\n");
    return;
}