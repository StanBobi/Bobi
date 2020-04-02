/*
1. Sa se scrie un program care citeste de la tastura &quot;N&quot;
numere naturale. Pentru fiecare numar se va determina forma
lui binara, se va calcula inversul binar ,iar mai apoi se
introduce intr-o stiva forma binara inversata.
Ex:
Input : 27
Forma binara : 0001 1011
Forma binara stiva output: 1110 0100
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stiva
{
    int size;
    int val;
}p;

void initializare(p st[20][8],int maxim,int nr)
{
    int i;
   for(i=0;i<maxim;i++)
   {
       st[nr][i].val=0;
   }
}

void afisare(p st[20][8],int i,int nr)
{
    while(i>=0)
    {
        printf("%d ",st[nr][i].val);  // afisarea este inversa deoarece porneste din varful stivei
     i--;
    }
    printf("\n");
}

void binar(int x,int *bin)
{
   int i;
   *bin = 0;

   for(i=7;i>=0;i--)
   {
       *bin=(*bin)*10+(1&(x>>i));
   }
}

void adaugare(p st[20][8],int *k,int val,int nr)
{

    st[nr][(*k)].val=val;
 (*k)++;
}

void stergere(p st[20][8],int *k,int nr)
{
    (*k)--;
}

int main()
{
    int bin=0,N,x,i,k,j; //k este folosit pentru pozitie
    p st[20][8];



    printf("N=");scanf("%d",&N);

    for(i=0;i<N;i++)
    {
     initializare(st,8,i);
     k=0;

     printf("x=");scanf("%d",&x);

     binar(x,&bin);

     for(j=0;j<8;j++)
     {
      if((1&(x>>j))==1) adaugare(st,&k,0,i);
      else adaugare(st,&k,1,i);
     }

     afisare(st,k-1,i);

    }

    return 0;
}
