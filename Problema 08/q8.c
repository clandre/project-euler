#include<stdio.h>
#include<stdlib.h>

int* preenche_vet(int *vet);

int main(void)
{
    int i,j;
    int *vet = (int*)malloc(1000*sizeof(int));

    vet = preenche_vet(vet);
    printf("\nMaior: %d\n",resposta(vet));
    getch();

    return 0;
}

int* preenche_vet(int *vet)
{
    FILE *arq = fopen("dados.txt","rt");
    int i=0,aux;

    while(!feof(arq))
    {
        if(!feof(arq))
        {
            fscanf(arq,"%d ",&aux);
            //printf("%d ",aux);
            vet[i]  =  aux;
            i++;
        }
    }
    fclose(arq);
    return vet;
}

int resposta(int *vet)
{
    int maior = 0,resp;
    int i;

    for(i = 0; i < 1000; i++)
    {
        resp = (vet[i]*vet[i+1]*vet[i+2]*vet[i+3]*vet[i+4]);
        if(resp > maior)
            maior = resp;
    }
    return maior;
}
