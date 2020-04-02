/*
2. Se citeste de la tastatura un numar C cu valori posibile
intre 0-7. Dupa citirea numarului &quot;C&quot; se vor citi de la tastatura
&quot;N&quot; numere iar acele numere care au reprezentarea lor
binara, bitul de pe pozitia &quot;C&quot; cu valoare 1, vor fi introduse
intr-o stiva. Sa se afiseze in final tot continutul stivei
(indiferent de ordine)
Ex:
C = 2
N = 5
- Acum se citesc 5 numere:
1 2 3 4 5
- Se afiseaza la sfarsit
4 5
Deoarece 4 = 100 si 5 = 101, bitul de pe pozitia &quot;2&quot; este &quot;1&quot;
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stiva
{
    int size,val;
}p;

void initializare(p *st,int maxim)
{
    int i;
   for(i=0;i<maxim;i++)
   {
        (st+i)->val=0;
       (st+i)->size=maxim;
   }
}

void afisare(p *st,int i)
{
    while(i>=0)
    {
        printf("%d ",(st+i)->val);  // afisarea este inversa deoarece porneste din varful stivei
     i--;
    }
    printf("\n");
}

void adaugare(p *st,int *k,int val)
{
  if((*k)<=((st+((*k)-1))->size))  // ma uit la penultima valoare din stiva pentru ca am memorata marimea maxima
  {
 (st+(*k))->val=val;
 (*k)++;
  }
  else printf("Stiva este plina!");
}

void stergere(p *st,int *k)
{
    (*k)--;
}

int main()
{
    int x,C,N,k=0,i;
    p *st;

    printf("C=");scanf("%d",&C);
    printf("N=");scanf("%d",&N);

    st=(p*)malloc(sizeof(p)*N);

    initializare(st,N);

    for(i=0;i<N;i++)
    {
        printf("x=");scanf("%d",&x);
        if((1&(x>>C))==1) adaugare(st,&k,x);
    }

     afisare(st,k-1);

    return 0;
}
