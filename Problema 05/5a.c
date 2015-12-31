#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int i=1,j;
    int achou = 0;
    int cont = 0;


   // printf("%d\n",sizeof(long double));
    //getch();

    do
    {
        cont = 0;
        for(j = 1; j <= 10; j++)
        {
            if(i % j == 0)
                cont++;
        }
        if(cont == 10)
        {
            //achou = 1;
            printf("Aqui: %d\n",i);
            getch();
            break;
        }
        printf("%d\n",i);
        i++;
    }
    while((i < 5000));
    printf("O menor valor eh: %d\n",i);
    getch();
    return 0;
}
