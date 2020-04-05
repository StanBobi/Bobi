#include <stdio.h>
#include <stdlib.h>

int valid(int k,int v[20])
{
     if(k>1) if(v[k]-v[k-1]>1) return 0;   //verificam ca laturile sunt adiacente
    return 1;
}

int afisare(int v[20],int n,int a[20][20])
{
  int i,s=0;
   for(i=1;i<=n;i++) s=s+a[i][v[i]];       // functia de afisare va returna suma elementelor, nu afiseaza nimic

   return s;
}

void back(int n,int a[20][20])
{
    int k=1,v[20],ok=0,smax=0;
    v[k]=0;
    while(k>0)
    {
        if(k<=n)
        {
            do{
                if(v[k]<k){     //verific in legatura cu k nu cu n, pentru ca in varf nu am atatea elemente cate am la baza
                        v[k]++;
                        ok=1;
                          }
                else ok=0;
            }while(valid(k,v)==0&&ok==1);
        }
        if(ok==1){ if(k==n) {if(afisare(v,n,a)>smax) smax=afisare(v,n,a);  }  // o verificare daca suma este maxima
                   else {k++;
                        v[k]=0;}
        }
        else k--;
    }
    printf("\n%d\n",smax);
}

void citire_pir(int v[20][20],int n) //initializarea si citirea piramidei
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            v[i][j]=0;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("v[%d][%d]=",i,j);
            scanf("%d",&v[i][j]);
        }
    }
}

int main()
{
    int n,v[20][20];

    printf("numarul de linii ale piramidei:");
    scanf("%d",&n);

    citire_pir(v,n);

    back(n,v);

    return 0;
}
