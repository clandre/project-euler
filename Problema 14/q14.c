#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void getch(void){
    system("read b");
}

typedef struct lista
{
    long long int num;
    struct lista *prox;
} Lista;

Lista* inserir(Lista *l,long long int n);
int par(long long int n);
int calcula(Lista *numeros,long long int n);
int tamanho(long long int n);
void imprime(Lista *l);
Lista* limpa_lista(Lista *l);
int existe(Lista *l,long long int n);

int main(void)
{
    time_t inicio,fim;
    double total;
    Lista *numeros = NULL;
    long long int i,n,aux,maior = 0;

    inicio = time(NULL);

    for(i = 1; i < 1000000; i++)
    {
        aux = calcula(numeros,i);
        if(aux > maior)
        {
            maior = aux;
            n = i;
        }
    }
    fim = time(NULL);
    total = difftime(fim,inicio);
    printf("\nMaior: %lld\nSequencia: %lld em %lf segundos.\n",n,maior,total);
    return 0;
}

int par(long long int n)
{
    if(n % 2 == 0)
        return 1;
    else
        return 0;
}

int calcula(Lista *numeros,long long int n)
{
    int cont = 1;
    long long int aux;
    do
    {
        if(!existe(numeros,n))
        {
            aux = n;
            if(par(n))
                n /= 2;
            else
                n = (3*n) + 1;
            numeros = inserir(numeros,aux);
            cont++;
        }
        else
            return 1 + tamanho(n);
    }while(n != 1);

    return cont;
}

Lista* inserir(Lista *l,long long int n)
{
    if(l == NULL)
    {
        Lista *no = (Lista*)malloc(sizeof(Lista));
        no->num = n;
        no->prox = NULL;
        l = no;
    }
    else if(n > l->num){
        Lista *no = (Lista*)malloc(sizeof(Lista));
        no->num = n;
        no->prox = l;
        l = no;
    }
    else
    {
        l->prox = inserir(l->prox,n);
    }
    return l;
}

int existe(Lista *l,long long int n)
{
    if(l != NULL)
    {
        if(l->num == n)
            return 1;
        if(l->num < n)
            return 0;
        else
            return existe(l->prox,n);
    }
    return 0;
}

void imprime(Lista *l){
    if(l != NULL){
        printf("%lld ",l->num);
        imprime(l->prox);
    }
}

int tamanho(long long int n)
{
    int cont = 1;
    do
    {
        if(par(n))
            n /= 2;
        else
            n = (3*n) + 1;
        cont++;
    }
    while(n != 1);
    return cont;
}

Lista* limpa_lista(Lista *l)
{
   if(l->prox == NULL)
   {
       free(l);
   }
   else
   {
       l->prox = limpa_lista(l->prox);
   }
   return l->prox;
}
