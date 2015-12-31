#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"gmp.h"

int main(void)
{
    time_t inicio,fim;
    double total;
    mpz_t a,b;
    mpz_init(a);
    mpz_init(b);
    int i = 1;
    char str[51];

    inicio = time(NULL);
    FILE * arq = fopen("dados.txt","rt");

    if(arq != NULL)
    {
 	mpz_set_str(a,"0000000000",10);
        while(fgets(str,51,arq) != NULL)
        {
		if(i % 2 == 1){
			mpz_set_str(b,str,10);
			mpz_add(a,a,b);
			printf("Temporario:");
			gmp_printf("\n    %Zd\n",a);
		}
		i++;		
        }
	    fim = time(NULL);
	    total = difftime(fim,inicio);
	    printf("Resposta: ");
	    gmp_printf("\n    %Zd em %ld segundos.\n",a,total);
    }
    else
        printf("Nao foi possivel abrir o arquivo!\n");
    return 0;
}
