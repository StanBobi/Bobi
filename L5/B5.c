#include <stdio.h>
#include <stdlib.h>

void functia(int *n,int *v)
{
    int *k;
    if(*n>0){
  k=(int*)malloc(sizeof(int));
  v=(int*)malloc(sizeof(int));
  printf("x=");scanf("%d",(v+(*n)));
  *k=*n-1;
  printf("Se adauga un element in stiva.Mai sunt %d casute goale.\n",*n-1);
  functia(k,v);

    }
    else printf("Nu mai este nici o casuta goala\n");
}
int main()
{
    int x,*v;
    x=7;
    functia(&x,v);
    return 0;
}
