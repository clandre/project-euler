#include <stdlib.h>
#include <stdio.h>
#include "Matematica.h"

struct fdiv
{
    int base;
    int expoente;
};

long int numeroTriangular(int n)
{
    // somátorio de 1 até n
    return (n*(n+1))/2;
}

int* fatoracao(int n,int *pos)
{
// n é o número, e vet será o vetor que conterá os divisores
    int *vet = (int*)malloc(sizeof(int));
    int i = 2;

    *pos=0;

    while(n != 1)
    {
        if((n % i) == 0)
        {
            vet[*pos] = i;
            *pos += 1;
            vet = (int*)realloc(vet,(*pos+1)*sizeof(int));
            n /= i;
        }
        else
            i++;
    }
    return vet;
}

int conta(int *vet,int m)
{
    int i,cont=0;

    for (i = 0; i < m; i++)
    {
        if(vet[i] != vet[i-1])
            cont++;
    }
    return cont;
}

Fdiv fDivisores(int *vet, int m,int tamanho)
{
    int i,j,k,pos=0,cont=1;

    int aux[tamanho];

    Fdiv resp = (Fdiv)malloc((tamanho)*sizeof(struct fdiv));

    for(i = 0; i < m; i++)
    {
        for(j = i+1; j <= m; j++)
        {
            if(vet[i] == vet[j])
                cont++;
        }
        if(existe(aux,vet[i],tamanho) == 0)
        {
            resp = inserir(resp, vet[i], cont, pos);
            aux[pos] = vet[i];
            pos += 1;
        }
        cont = 1;
    }
    return resp;
}

Fdiv inserir(Fdiv resp,int x,int y, int pos)
{
    
    resp[pos].base = x;
    resp[pos].expoente = y;
    return resp;
}

int existe(int *resp,int x,int tamanho)
{
    int i;
    for(i = 0; i < (tamanho); i++)
    {
        if(resp[i] == x)
            return 1;
    }
    return 0;
}

void imprime(Fdiv vet,int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        printf("Base: %d\nExpoente: %d\n\n",vet[i].base,vet[i].expoente);
    }
}

int totalDivisores(Fdiv resp, int tam)
{
    int i,total = 1;
    for(i = 0; i < tam; i++)
    {
        total *= (resp[i].expoente + 1);
    }
    return total;
}
