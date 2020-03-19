#include <stdio.h>
#include <stdlib.h>

void suma(int n,int v[20],int *s)
{
   int i;
   for(i=0;i<n;i++) (*s)=(*s)+v[i];

}

int main()
{   int n,i,*v,s;

    printf("n=");
    scanf("%d",&n);

    v=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("v[%d]=",i+1);
        scanf("%d",(v+i));
    }
    s=0;

    suma(n,v,&s);

    printf("%d",s);

    return 0;
}
