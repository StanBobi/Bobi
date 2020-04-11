#include <stdio.h>
#include <stdlib.h>

void binar(int x)
{
    int s=0,p=1;
   while(x)
   {
       s=(x%2)*p+s;
    x=x/2;
    p=p*10;
    }
    printf("%d\n",s);
}

int main()
{
    int n,i,x,j;

    printf("Cate numere vreti sa cititi?");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
      printf("x(%d)=",i+1);scanf("%d",&x);
      binar(x);

      for(j=0;j<8;j++)
      {
          if((1&(x>>j))==1) x=x&~(1<<j);
          else x=x|(1<<j);
      }
      binar(x);
      printf("%d",x);

    }

    return 0;
}
