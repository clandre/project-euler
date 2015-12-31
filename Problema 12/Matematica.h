#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED

typedef struct fdiv *Fdiv;
int* fatoracao(int n, int *pos);
int conta(int *vet,int pos);
Fdiv fDivisores(int *vet, int m,int tamanho);
Fdiv inserir(Fdiv resp,int x,int y, int pos,int tamanho);
int existe(int *resp,int x,int tamanho);
void imprime(Fdiv vet,int m);
int totalDivisores(Fdiv resp, int tam);

#endif // MATEMATICA_H_INCLUDED
