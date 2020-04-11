/*
4. Sa se realizeze o implementare de stiva FARA a ne folosii
variabile globale iar TOATE variabilele trebuiesc sa fie
pointeri. Stiva este de numere intregi. Se va introduce in
stiva 7 numere de tip intreg. - Sunt necesare toate metodele
(de verificat plin / gol / peek / push / pop)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stiva
{
    int size,val;
}p;

void initializare(p *st)
{
    int i;
    for(i=0;i<7;i++)
    {
        (st+i)->val='NULL';
        (st+i)->size=7;
    }
}

void afisare(p *st,int x)
{
   if(x>(st+x)->size) {printf("S-a depasit dimensiunea stivei\n");
                      exit(0);}

    else      {
            if(x>=0) {printf("%d ",(st+x)->val);
             afisare(st,x-1);}
             }
}

void stergere(p *st,int *x)
{
    if((*x)==0) printf("Nu mai exista element de sters\n");
        else (*x)--;
}

void adaugare(p *st,int x)
{
    int n;
      if(x<7) {
            printf("x=");
            scanf("%d",&n);
            (st+x)->val=n;
            adaugare(st,x+1);
            }
}

int main()
{   // putea sa fac un meniu pentru apelarea fiecarei functii in mod separat si cand se dorea, dar nu pot folosi variabile globare :(
    p *st;

    st=(p*)malloc(sizeof(p)*7);// aceasta este stiva pentru elemente, initializez cu N in caz ca toate numerele sunt palindroame

    adaugare(st,0);

    afisare(st,6);


    return 0;
}
