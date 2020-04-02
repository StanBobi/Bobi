/*
6. Se citeste de la tastatura un numar zecimal pâna în 255. Sa
se Înscrie într-o stiva reprezentarea sa binara. Sa se
genereze pe stack cea mai mare valoarea posibila.
A) Sa se implementeze citirea conditionata pâna la 255.
B) Sa se realizeze transformarea din zecimal în binar.
C) Adaugarea fiecarui bit într-o stiva
D) Sa se genereze valoarea maxima posibila din valorile de
pe stiva.
27 -&gt; 0001 1011 (val binara) – Stack initial
1111 0000 – Valoarea maxima
5 -&gt; 0000 0101 (val binara) – Stack initial
1100 0000 – Valoarea maxima
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stiva
{
   int val,max;
}p;

void init(p st[8],int x,int *nr)
{
    if((*nr)!=8){
        st[(*nr)].val=0;
        st[(*nr)].max=x;
        (*nr)++;
    }
}

void add(p st[8],int *nr,int x)
{
    st[(*nr)].val=x;
    (*nr)++;
}

void stergere(p st[8],int *nr)
{
    st[(*nr)].val=0;
    (*nr)--;
}

void afisare(p st[8],int nr)
{
    while(nr>=0)
    {
        printf("%d",st[nr].val);
        nr--;
    }
}

int main()
{
    p st[8];
    int nr,n,i,kk=0;

    nr=0;

    init(st,9,&nr);

    printf("n=");scanf("%d",&n);
    nr=0;

    for(i=0;i<=7;i++)
    {
      add(st,&nr,(1&(n>>i)));
    }

    afisare(st,nr-1);

    while(nr){
        stergere(st,&nr);
    }

    for(i=0;i<=7;i++)
    {
      if((1&(n>>i))==0) kk++;
    }

    while(nr<8)
    {
        if(kk!=0) {add(st,&nr,0);
                  kk--;}
        else add(st,&nr,1);
    }
    printf("\n");
    afisare(st,nr-1);


    return 0;
}
