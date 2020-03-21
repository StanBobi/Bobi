#include <stdio.h>
#include <stdlib.h>

int MannaPnueli(int x)
{
    if(x>=12) return x-1;
    else MannaPnueli(MannaPnueli(x+2));
}

int main()
{
    int x;

    printf("x=");scanf("%d",&x);
    printf("%d", MannaPnueli(x));
    return 0;
}
