#include <stdio.h>
#include <stdlib.h>

int main()
{   int n,x,nr=7;
    x=0;

    printf("n=");scanf("%d",&n);

    while(nr>=0)
    {
     if((1&(n>>nr))==0) x=x|(1<<nr);
     printf("%d",(1&(n>>nr)));
     nr--;
    }
    printf("\n");

    nr=7;
    while(nr>=0)
    {
        printf("%d",(1&(x>>nr)));
        nr--;
    }

    printf("\n");

    printf("%d",x);
    return 0;
}
