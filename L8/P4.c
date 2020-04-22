/*
4. Sa se implementeze suma numerelor pana la “N” printr-o functie recursiva si prin metodele
repetitive (for, while, do while)
*/
#include <stdio.h>
#include <stdlib.h>

int suma_incepe_cu_1(int x,int N)
{
    if(N==x) return x;
    else return x+suma_incepe_cu_1(x+1,N);
}

int suma_de_la_N(int N)
{
    if(N==1) return 1;
    else return N+suma_de_la_N(N-1);
}

int main()
{
    int i,s=0,N;

    printf("N = ");scanf("%d",&N);

    printf("\nSuma cu subprogram incepand de la 1 pana la N : %d\n",suma_incepe_cu_1(1,N));

    printf("\nSuma cu subprogram de la N la 1 : %d\n",suma_de_la_N(N));

    s=0;  //initalizam suma cu 0

    for(i=1;i<=N;i++)
       s=s+i;

    printf("\nSuma cu for este : %d\n",s);

    s=0;
    i=N;
    while(i!=0)
    {
        s=s+i;
        i--;
    }

    printf("\nSuma cu while este : %d\n",s);

    i=1;
    s=0;

    do{
        s=s+i;
        i++;
    }while(i<=N);

    printf("\nSuma cu do-while este : %d\n",s);

    //ala ce-mi copiezi tema, fara ca macar sa ai bunul simt sa modifici ceva
    //sa nu fie vizibil (chiar daca e evident)
    // sper sa pici la Boraci :*

    return 0;
}
