#include <stdio.h>
#include <stdlib.h>

void init(int N,int v[20])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("v[%d] = ",i+1);scanf("%d",&v[i]);
    }
}

void swap(int *x,int *y)
{   // aici are loc interschimbarea, cu paramametrii de referinta pentru a fi primite mai departe valorile
    int aux=(*x);
    (*x)=(*y);
    (*y)=aux;
}
void Bsort_2(int j,int n,int v[20])   // acesta ar fi in mod normal for ul de j
{
    if(j<n){  // merge pana la n(n isi are valoarea n-i-1(tipica bubble sort-ului) din subprogramul anterior)
            if(v[j]>v[j+1]) swap(&v[j],&v[j+1]);   // in cazul in care este nevoie se va face schimbarea
             Bsort_2(j+1,n,v);
           }
}

void Bsort_init(int i,int N,int v[20])
{
    if(i<N-1)   // acesta ia locul forului care merge pana la n-2
    {
        Bsort_2(0,N-i-1,v);  // dupa care in mod normal intra in forul de j
        Bsort_init(i+1,N,v);
    }
}

void afisare(int v[20],int N)
{
    int i;

    for(i=0;i<N;i++) printf("%d ",v[i]);
}

int main()
{
    int N,v[20];

    printf("N = ");scanf("%d",&N);

    init(N,v);

    Bsort_init(0,N,v);  // acesta, ar fi for ul de i, care incepe de la 0 pana la N-2

    afisare(v,N);

    return 0;
}
