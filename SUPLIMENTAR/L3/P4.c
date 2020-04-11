#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,x=0,y=0,i,s=0,k=0;

    printf("a=");scanf("%d",&a);
    printf("b=");scanf("%d",&b);

    for(i=7;i>=0;i--)
    {
        x=x*10+(1&(a>>i));
        y=y*10+(1&(b>>i));
    }

    if(a==b) {  // fac aceasta verificare pentru ca am observat ca patratul numerelor nu merge sa il fac cu alta metoda
               for(i=0;i<a;i++)
              {
              s=s+b;
               }

               for(i=7;i>=0;i--)
               k=k*10+(1&(s>>i));

              printf("%d \n",k);
             }

    else {   s=0;
            for(i=0;i<x;i++)
             s=s+y;
             printf("%d",s);
           }

    return 0;
}
