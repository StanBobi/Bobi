#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,C,N,*v,k=0;

    do{
        printf("C=");
        scanf("%d",&C);
    }while(C<0||C>7);

    printf("N=");
    scanf("%d",&N);

    v=(int*)malloc(sizeof(int)*N);

    while(N)
    {
       printf("x=");
       scanf("%d",&x);

       if((1&(x>>C))==1) {*(v+k)=x;
                         k++;}
        N--;
    }

    for(x=0;x<k;x++) printf("%d ",*(v+x));

    return 0;
}
