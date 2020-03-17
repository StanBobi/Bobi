#include <stdio.h>
#include <stdlib.h>

/*
int suma(int n,int *v,int &x)
{
    int i;
   for(i=0;i<n;i++) x=x+v[i];
}
asta ar fi rezolvarea pentru transmiterea prin referinta
*/

int suma(int n,int v[20]) // am folosit int pentru ca nu pot folosi transmiterea prin referinta in C
{
   int i,k=0;
   for(i=0;i<n;i++) k=k+v[i];

    return k;
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

    s=suma(n,v);

    printf("%d",s);

    return 0;
}
