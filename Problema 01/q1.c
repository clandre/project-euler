#include<stdio.h>


int main(void){
    int i,resp=0;
    for (i = 1;i < 1000; i++)
        if((i % 3 == 0) || (i % 5 == 0))
            resp += i;
    printf("\nA soma eh: %d.\n",resp);
    return 0;
}
