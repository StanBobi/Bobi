#include <stdio.h>
#include <stdlib.h>

int valid(int k,int st[20],int n,int v[20])
{
    int i,ok1=0,ok2=1;

    for(i=0;i<n;i++)
    {
        if(st[k]==v[i]) {ok1=1;
                         i=n;}
    }

    for(i=1;i<k;i++)
        if(st[i]==st[k]) ok2=0;

    if(ok1==1&&ok2==1) return 1;
    else return 0;
}

void afisare(int k,int st[20])
{
    int i;

    for(i=1;i<=k;i++) printf("%d",st[i]);

     printf("\n");
}

void back(int n,int v[20])
{
    int ok,k=1,st[20];
    st[k]=-1;

    while(k>0)
    {
        if(k<=n){
            do{

               if(st[k]<9){
                st[k]++;
                ok=1;
               }
                else ok=0;
            }while(ok==1&&valid(k,st,n,v)==0);
        }

        if(ok==1){ if(k==4) afisare(k,st);
                   else{
                    k++;
                    st[k]=-1;
                   }
        }
       else k--;
    }
}

int main()
{
    int i,n,v[20];

    do{
    printf("Cate numere isi aminteste Vasile?(minim 4):");
    scanf("%d",&n);
    }while(n<4);

    for(i=0;i<n;i++)
    {
    do{
    printf("Numarul pe care si-l aminteste:");
    scanf("%d",&v[i]);
    }while(v[i]>9||v[i]<0);
    }

    back(n,v);

    return 0;
}
