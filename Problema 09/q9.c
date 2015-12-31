#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    int a,b,c;

    for(a = 0; a < 1000; a++)
        for(b = 0; b < 1000; b++)
        {
            c = 1000 - (a + b);
            if((a < b) && (b < c))
                if((a*a)+(b*b) == (c*c))
                    printf("A: %d\nB: %d\nC: %d\tResp: %d\n",a,b,c,(a*b*c));
        }
    return 0;
}
