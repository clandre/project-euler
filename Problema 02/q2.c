#include<stdio.h>

int main(void)
{
    int x,i=1,resp = 0;
    //printf("%d\n",fibo(5));
    do
    {
        x = fibo(i);
        if(x % 2 == 0)
            resp += x;
        i++;
    }
    while(x < 4000000);
    printf("Resp: %d",resp);
    return 0;
}



int fibo(int n)
{
    if((n == 1) || (n == 2))
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}
