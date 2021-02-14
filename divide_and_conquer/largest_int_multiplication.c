#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power(int num,int power)
{
    int result=1;
    for(int i=1;i<=power;i++)
    {
        result *= num;
    }
    return result;
}

int length(int num)
{
    int i=0;
    while(num>0)
    {
        num = num/10;
        i++;
    }
    return i;
}

int kasturba(int num1, int num2)
{
    int a,b,c,d;
    int n = length(num1);

    if(n==1)
        return num1*num2;

    int nby2 = n/2;

    a = num1 / power(10,nby2);
    b = num1 % power(10,nby2);
    c = num2 / power(10,nby2);
    d = num2 % power(10,nby2);

    int ac = kasturba(a,c);
    int bd = kasturba(b,d);
    int ad = kasturba(a,d);
    int bc = kasturba(b,c);
    int tenpower = power(10,n);
    int tenpowerby2 = power(10,nby2);

    return tenpower * ac + tenpowerby2 * (ad + bc) + bd;
}

void main()
{
    int num1,num2;
    printf("n1 and n2?\n");
    scanf("%d%d",&num1,&num2);

    printf("lentgh check = %d\n",length(num1));
    int result = kasturba(num1,num2);
    printf("result : %d\n",result);
}