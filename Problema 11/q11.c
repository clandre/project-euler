#include<stdio.h>
#include<stdlib.h>

int** Cria_Matriz();
void Imprime(int **mat);
int bDireita(int **mat);

int main(void)
{
    int i,maior=0,aux;
    int **mat;

    mat = Cria_Matriz();
    //Imprime(mat);
    //printf("\nCriou\n");

    //getch();
    aux = bDireita(mat);
    //printf("\nBusca Direita: %d\n\n",aux);
    if(aux > maior)
        maior = aux;

    aux = bBaixo(mat);

    if(aux > maior)
        maior = aux;

    aux = bDiagonald(mat);

    //printf("Busca Diagonal Direita: %d\n\n",aux);
    if(aux > maior)
        maior = aux;
    //getch();

    aux = bDiagonale(mat);

    //printf("Busca Diagonal Esquerda: %d\n\n",aux);
    if(aux > maior)
        maior = aux;
    //getch();
    printf("\nMaior Total: %d\n\n",maior);
    //getch();
    return 0;
}

int** Cria_Matriz()
{
    int i,j;
    int **mat = (int**)malloc(20*sizeof(int));
    for(i = 0; i < 20; i++)
    {
        mat[i] = (int*)malloc(20*sizeof(int));
    }

    FILE *arq = fopen("dados.txt","rt");

    while(!feof(arq))
    {
        if(!feof(arq))
        {
            for(i = 0; i < 20; i++)
                for(j = 0; j < 20; j++)
                    fscanf(arq,"%d ",&mat[i][j]);
        }
    }
    return mat;
}

void Imprime(int **mat)
{
    int i,j;

    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int bDireita(int **mat)
{
    int maior = 0,resp;
    int i,j;

    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 17 ; j++)
        {
            resp = ((mat[i][j])*(mat[i][j+1])*(mat[i][j+2])*(mat[i][j+3]));
            if (resp > maior)
                maior = resp;
        }
    }
    return maior;
}

int bBaixo(int **mat)
{
    int maior = 0,resp;
    int i,j;

    for(i = 0; i < 17; i++)
    {
        for(j = 0; j < 20; j++)
        {
            resp = ((mat[i][j])*(mat[i+1][j])*(mat[i+2][j])*(mat[i+3][j]));
            if(resp > maior)
                maior = resp;
        }
    }
    return maior;
}

int bDiagonald(int **mat)
{
    int maior = 0, resp;
    int i,j;

    for(i = 0; i < 17; i++)
    {
        for(j = 0; j < 17; j++)
        {
            resp = ((mat[i][j])*(mat[i+1][j+1])*(mat[i+2][j+2])*(mat[i+3][j+3]));
            if(resp > maior)
                maior = resp;
        }
    }
    return maior;
}

int bDiagonale(int **mat)
{
    int maior=0,resp;
    int i,j;

    for(i = 0; i < 17; i++)
    {
        for(j = 3; j < 20; j++)
        {
            resp = ((mat[i][j])*(mat[i+1][j-1])*(mat[i+2][j-2])*(mat[i+3][j-3]));
            if(resp > maior)
                maior = resp;
        }
    }
    return maior;
}
