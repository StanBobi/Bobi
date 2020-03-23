#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void functie(char *E,char *s,char *c)
{
   int i,x=0,nr=0;
   char sk[20],ck[20],aux,newsir[20];
   i=0;

   if(i==0&&E[i]!='(') {printf("Eroare! Primul caracter trebuie sa fie paranteza!");
                       exit(0);}
   else i++;


    do{
      if(E[i]>='a'&&E[i]<='z') {    //verificam daca este caracter
            c[strlen(c)+1]='\0';
            c[strlen(c)]=E[i];
      }
      else if((E[i]=='*'||E[i]=='/'||E[i]=='+'||E[i]=='-')&&E[i+1]=='('){ //aici nu sunt sigur daca trebuia sa fac si pentru adunare si scadere sau doar pentru inmultiri impartiri
                aux=E[i];
                i++;
                nr=0;
                while(E[i]!=')')
                {
                   newsir[nr]=E[i];
                   nr++;
                   newsir[nr]='\0';
                   i++;
                }                     //luam sirul dintre paranteze si il vom imparti la randul lui in caractere si semne

                newsir[nr]=')';
                newsir[nr+1]='\0';
                strcpy(sk,"");
                strcpy(ck,"");
                functie(newsir,sk,ck);  //folosim doua variabile noi pentru semne si caractere
                strcat(c,ck);      //lipim de sirul caracterelor noile caractere, acestea fiind cele dintre paranteze
                strcat(c,sk);    // lipim si semnele luate dintre paranteze
                c[strlen(c)+1]='\0';
                c[strlen(c)]=aux;  //adaugam semnul dinaintea parantezei
              }

      else if(E[i]=='*'||E[i]=='/'||E[i]=='+'||E[i]=='-'){  //verificam daca este semn
    *(s+x)=E[i];
      x++;
      *(s+x)='\0';
      }

      i++;
    }while(E[i]!=')'&&i<strlen(E));

       strrev(s);  //luam semnele in ordine inversa


}
int main()
{
    char E[20],s[20],c[20];

    printf("E=");scanf("%s",E);
    strcpy(s,"");
    strcpy(c,"");

   functie(E,s,c);
   strcat(c,s);  //lipim semnele de sa zisele caractere
   printf("%s\n",c);

    return 0;
}
