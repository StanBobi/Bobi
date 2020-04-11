/*
7. Sa se scrie un program care verifica daca un numar citit de
la tastatura pâna în valoarea de 65535 este palindrom atât în
baza 2 cât si în baza 10. Verificarea ca numarul ar fi
palindrom sa se implementeze cu ajutorul unui stack.
A) Sa se implementeze citirea conditionata pâna la 65535.
B) Sa se realizeze transformarea din zecimal în binar.
C) Adaugarea fiecarui bit într-un stack
D) Adaugarea fiecarei cifre într-un alt stack.
E) Verificarea ca cele doua variante sunt palindrom sau nu.
585 = 1001 0 0 1001 (binary) – PALINDROM
Palindrom – O secventa de caractere care se citeste exact la
fel indiferent de directia de citire (stânga dreapta sau dreapta
– stânga)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stiva
{
    int val;
}p;

int binar(int x)
{
    if(x) return x%2+10*binar(x/2);
    else return 0;
}

void add(p *st,int *nr,int x)
{
    (*nr)++;
    (st+(*nr))->val=x;

}
int valid(p *st,int nr,int x)
{
    while(nr>=0)
    {
        if((st+nr)->val!=x%10) return 0;
        x=x/10;
     nr--;
    }
    return 1;
}

void stergere(p *st,int *nr)
{
    (st+(*nr))->val='NULL';
    (*nr)--;
}

int main()
{
    int bin,x,nr=-1,k;
    p *st;
    st=(p*)malloc(sizeof(int)*6);

    printf("x=");scanf("%d",&x);
    bin=binar(x);

    k=x;

    while(k)
    {
        add(st,&nr,k%10);
        k=k/10;
    }

    if(valid(st,nr,x)==1) printf("%d este palindrom\n",x);
    else printf("%d nu este palindrom\n",x);

    k=bin;

    while(nr>=0)
    {
        stergere(st,&nr);
    }

    while(k)
    {
        add(st,&nr,k%10);
        k=k/10;
    }

    if(valid(st,nr,bin)==1) printf("%d este palindrom\n",bin);
    else printf("%d nu este palindrom\n",bin);

    return 0;
}
