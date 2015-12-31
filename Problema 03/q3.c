#include<stdio.h>
#include<stdlib.h>
#define num 600851475143

int* Divisores(int *vet, int *n);

//long long int num = 600851475143;
long long int num2 = num / 2;

int main(void)
{
    int i;
    int n = 0;
    int *vet = (int*)malloc(sizeof(int));
    vet = Divisores(vet,&n);
    printf("ok\n");
    for(i = 0; i < n;i++)
        printf("%d ",vet[i]);

    return 0;
}

int* Divisores(int *vet,int *n)
{
    long long int i;

    for(i = 1; i <= num2; i++){
        if(num % i == 0)
        {
            printf("I: %d\n",i);
            //printf("\nFor\n");
            vet[(*n)] = i;
            vet = (int*)realloc(vet,((*n)+1)*sizeof(int));
            //printf("\nRealocou\n");
            //getch();
            (*n)++;
           // printf("N: %d\n",(*n));
        }
       // printf("For: %lld\n",i);
    }
    return vet;
}

