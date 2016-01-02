#include<stdio.h>
#include<time.h>
#include<math.h>
#include "Matematica.h"

int main(void)
{
    time_t inicio,fim;
    int y=0,cont=0;

    int* aux,pos;
    int divdiferentes;
    long int n;

    inicio = time(NULL);
    while(cont < 500)
    {
        y++;
        n = numeroTriangular(y);
        aux = fatoracao(n,&pos);
        divdiferentes = conta(aux,pos);        
        Fdiv resp = fDivisores(aux,pos,divdiferentes);
        cont = totalDivisores(resp,divdiferentes);
    }
    printf("Resposta: %ld\n",n);
    fim = time(NULL);
    printf("Tempo de execucao: %.2f\n",difftime(fim,inicio));
    return 0;
}