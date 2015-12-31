#include<stdio.h>
#include<stdlib.h>

int testa_primo(int n);

int main(void)
{
    long int i,resp = 0;

    for(i = 2; i < 2000000; i++)
        if(testa_primo(i) == 1)
            resp += i;
    printf("\nO resultado eh: %li.\n",resp);
    getch();
    return 0;
}

int testa_primo(int n)
{
    long int i;
    for(i = 2; i <= (int)(n/2); i++)
        if(n % i == 0)
            return 0;
    return 1;
}
