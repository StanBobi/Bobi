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
        (st+i)->val='NULL';
        (st+i)->size=maxim;
    }
}

void stiva_oglinda(p *og,int x,int *k)
{
   while(x&&(*k)<=(og+(*k))->size)
   {
       (og+(*k))->val=x%10;
       (*k)++;
       x=x/10;
   }
   if((*k)>(og+(*k))->size) {printf("Valori prea mari!");
                            exit(0);}
}

void afisare(p *st,int x)
{
    if(x>=0) {printf("%d ",(st+x)->val);
             afisare(st,x-1);}
}

int valid(p *og,int i,int x)
{
    if(x<10) return 1;

   else{

        if((og+i)->val!=x%10) return 0;
       valid(og,i-1,x/10);
       }
}


int main()
{
    int x,N,i,k,nr=0;
    p *st,*og;

    printf("N=");scanf("%d",&N);

    st=(p*)malloc(sizeof(p)*N);// aceasta este stiva pentru elemente, initializez cu N in caz ca toate numerele sunt palindroame

    initializare(st,N);

    for(i=0;i<N;i++)
    {   k=0;
        printf("x=");scanf("%d",&x);

        og=(p*)malloc(sizeof(p)*8);

        initializare(og,8);
        stiva_oglinda(og,x,&k);
        if(valid(og,k-1,x)==1) {(st+nr)->val=x;
                                  nr++;
                               }
    }

    afisare(st,nr-1);


    return 0;
}
