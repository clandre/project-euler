#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(void)
{
    int somadaspotencias = 0;
    int potenciadassomas = ((pow(100,2)+100)/2);
    int i,aux;

    for(i = 0; i < 101; i++)
    {
        aux = pow(i,2);
        somadaspotencias += aux;
        //printf("%d\n",aux);
    }
    potenciadassomas = pow(potenciadassomas,2);
    printf("%d\n",potenciadassomas-somadaspotencias);
    getch();
        return 0;
    }
