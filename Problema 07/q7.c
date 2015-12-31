#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int cont = 0;
    int i = 2;
    int aux;

    do
    {
        aux = testa_primo(i);
        if(aux == 1)
            cont++;
        i++;
    }
    while(cont != 10001);
    printf("The 10.001st prime number is: %d\n",i-1);
    getch();

    return 0;
}

int testa_primo(int n)
{
    int i;
    for(i = 2; i <=(n/2); i++)
        if(n % i == 0)
            return 0;
    return 1;
}
