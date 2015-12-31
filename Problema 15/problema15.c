#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <time.h>
#define n 20
#define tamanhoMatriz ((n+1)*(n+1))

void imprimir(gsl_matrix *matriz, int x);
void inicializarMatriz(gsl_matrix *matriz);

int main(void)
{
    clock_t begin, end;
    double time_spent;

    begin = clock();

    gsl_matrix *matrizAdjacencia = gsl_matrix_alloc (tamanhoMatriz, tamanhoMatriz);
    gsl_matrix_set_identity(matrizAdjacencia);
    inicializarMatriz(matrizAdjacencia);
    gsl_matrix *matrizAuxiliar = gsl_matrix_alloc (tamanhoMatriz, tamanhoMatriz);
    gsl_matrix_memcpy (matrizAuxiliar,matrizAdjacencia);
    gsl_matrix *matrizResultado = gsl_matrix_alloc (tamanhoMatriz, tamanhoMatriz);


    int i = 0;

    for(i = 0; i < ((2*n)-1); i++){
        gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
                  1.0, matrizAuxiliar, matrizAdjacencia,
                  0.0, matrizResultado);
        gsl_matrix_memcpy(matrizAuxiliar,matrizResultado);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Resposta: %f em %f segundos.\n",gsl_matrix_get(matrizResultado,0,tamanhoMatriz-1),time_spent);    
    return 0;
}

//Função que monta a matriz de adjacência
void inicializarMatriz(gsl_matrix *matriz)
{
    int i;

    for(i = 0; i < tamanhoMatriz; i++){
        if(((i+1) - 1 >= 1) && ((i+1) % (n+1) != 1)) //esquerda
            gsl_matrix_set(matriz,i,i-1,1);
        if(((i+1) + 1 <= (tamanhoMatriz)) && ((i+1) % (n+1) != 0)) //direita
            gsl_matrix_set(matriz,i,i+1,1);
        if((i+1) + (n+1) <= (tamanhoMatriz)) //baixo
            gsl_matrix_set(matriz,i,i+n+1,1);
        if((i+1) - (n+1) >= 1) //cima
            gsl_matrix_set(matriz,i,i-(n+1),1);
    }
}

void imprimir(gsl_matrix *matriz, int x){
	int i,j;

	for(i = 0; i < x; i++){
		for(j = 0; j < x; j++){
			printf("%d ",(int)gsl_matrix_get(matriz,i,j));
		}
        printf("\n");
	}
}