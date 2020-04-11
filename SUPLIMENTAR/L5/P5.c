#include <stdio.h>
#include <stdlib.h>

typedef struct stiva
{
    int max,val;
}p;

void adaugare_init(p *st,int x,int *nr)
{
    if(x<=50){
        (st+x)->val=x;
        (st+x)->max=50;
        adaugare_init(st,x+1,nr);
    }
    else (*nr)=x-1;
}

int valid(int x)
{
    int i;
    for(i=2;i<=x/2;i++)
    {
        if(x%i==0) return 1;
    }
    return 0;
}

int binar(int x)
{
    if(x) return x%2+10*binar(x/2);
    else return 0;
}

void stergere(p *st,int *nr)
{
    if((*nr)==-1) printf("Nu mai exista nimic de sters.");

    else {
    (st+(*nr))->val=0;
    (*nr)--;
    }
}

void add(p *st,int *nr,int x)
{
    (st+(*nr))->val=x;
    (*nr)++;
}

void impartire(p *st,int *nr,p *st2,int *x2)
{
    int nr1=0,nr2=0,i;
    p *prime,*bune;
    prime=(p*)malloc(sizeof(p)*51);
    bune=(p*)malloc(sizeof(p)*51);

    while((*nr)>0)
    {
        if(valid((st+(*nr))->val)==1){
          add(bune,&nr1,(st+(*nr))->val);
        }
        else {
            add(prime,&nr2,binar((st+(*nr))->val));
         }


    stergere(st,nr);
    }
    nr1--;
    nr2--;
    i=0;
    while(nr1>=0)
    {
        add(st,&i,(bune+nr1)->val);
        stergere(bune,&nr1);
    }
    (*nr)=i;

    i=0;
    while(nr2>=0)
    {
        add(st2,&i,(prime+nr2)->val);
        stergere(prime,&nr2);
    }
    (*x2)=i;
}

int main()
{
    p *st,*st2;
    int i,nr=0,x2=0;

    st=(p*)malloc(sizeof(p)*51);
    st2=(p*)malloc(sizeof(p)*51);

    adaugare_init(st,1,&nr);

    impartire(st,&nr,st2,&x2);

    for(i=0;i<nr;i++) printf("%d ",(st+i)->val);

    printf("\n");

    for(i=0;i<x2;i++) printf("%d ",(st2+i)->val);

    return 0;
}
