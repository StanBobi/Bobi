#include <stdio.h>
#include <stdlib.h>

void og(int x,int k,int *o)
{
    if(x!=0) og(x/10,k*10+x%10,o);
    else *o=k;
}

void afisare(int n,int v[20])
{
    if(n!=0) {printf("%d ",v[n]);
             afisare(n-1,v);}

}

int main()
{
    int k=0,n,o,N,i,v[20];

    printf("N=");scanf("%d",&N);

    for(i=0;i<N;i++)
{
    printf("n=");scanf("%d",&n);
    o=0;
    og(n,0,&o);
   if(n==o)
            {k++;
             v[k]=n;
            }
    }

     afisare(k,v);

    return 0;
}
