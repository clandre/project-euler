#include<stdio.h>
#include<stdlib.h>

int testa(int num);

int main(void)
{
    int i,j,maior=0,num,resp;

    for(i = 700; i < 1000; i++)
    {
        for(j = 700; j < 1000; j++)
        {
            num = i*j;
            resp = testa(num);
            if(resp == 1)
                if(num > maior)
                    maior = num;
        }
    }
    printf("Maior: %d\n",maior);
    getch();
    return 0;
}

int testa(int num)
{
    int val1=100000,val2=1,x,resp=0,i;
    int original = num;
    for(i = 0; i < 6; i++)
    {
        x = num / val1;
        num -= x * val1;
        val1 /= 10;
        resp += x * val2;
        val2 *= 10;
    }
    if(original == resp)
    {
        return 1;
    }
    else
        return 0;
}
