#include <stdio.h>
#include <stdlib.h>

int valid(int st[20],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(st[i]==st[k]) return 0;   // conditie pentru a nu se suprapune bombele
    }
    if(k>1) if(st[k]<st[k-1]) return 0; // conditia sa nu se faca de doua ori aceeasi solutie, gen 2 1 sau 1 2
    return 1;
}

void afisare(int st[20],int k)
{
    int i,j,s;
    int a[11][11];

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            a[i][j]=0;
    }

    for(i=1;i<=k;i++)
    {
     a[st[i]/10][st[i]%10]=-1;    // elementele din matrice sunt generate cu ajutorul stivei
    }

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            {
                s=0;    // se va face o suma pentru elemente din jur
        if(a[i][j]!=-1) {
            if(a[i-1][j]==-1) s++;
            if(a[i-1][j-1]==-1) s++;
            if(a[i-1][j+1]==-1) s++;
            if(a[i+1][j]==-1) s++;
            if(a[i+1][j-1]==-1) s++;
            if(a[i+1][j+1]==-1) s++;
            if(a[i][j+1]==-1) s++;
            if(a[i][j-1]==-1) s++;

            a[i][j]=s;
          printf("%d ",a[i][j]);
          }
            else printf("* ");
     }
        printf("\n");
    }



    printf("\n\n");
}

void back(int n)
{
    int st[20],k=1,ok;
    st[k]=-1;

    while(k!=0)
    {
      if(k<=n)
      {
          do{
            if(st[k]<100){  // valorile pot fii pana la 100 deoarece tabla este 10x10
                st[k]++;
                ok=1;
            }
            else ok=0;
          }while(ok==1&&valid(st,k)==0);
      }
     if(ok==1) { if(k==n) afisare(st,k);
                 else{
                    k++;
                    st[k]=-1;  //matricea incepe de la 0 deci si stiva va incepe de la -1
                 }

             }
     else k--;
    }
}

int main()
{
    int n;
    printf("Numarul de bombe:");
    scanf("%d",&n);

    back(n);

    return 0;
}
