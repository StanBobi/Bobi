#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,ok=1;

    printf("n=");scanf("%d",&n);

    for(i=0;i<7;i++)
    {
        if((1&(n>>i))==1) ok=0;
    }

    if(ok==1) printf("Numarul este 0\n");
   else if((1&(n>>i))==1) printf("\nNumarul este negativ\n"); //for-ul se opreste la 7 deci stim ca i este 7
        else printf("\nNumarul este pozitiv\n");

    return 0;
}
