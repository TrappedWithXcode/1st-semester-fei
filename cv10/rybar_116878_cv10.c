
/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:7               */
/*=======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {

    char priezvisko_meno[100];
    int rocnik;
    float priemer;
}STUDENT;

STUDENT *cMemoryS(int pocetS){
    STUDENT *p;
    p=(STUDENT *)malloc(pocetS * sizeof(STUDENT *));

    return p;

}

STUDENT *nacitajPole(char *subor, int *nacitane){
    FILE *fr;
    int i,check;
    char *checks,pomocna;
    STUDENT *pole;
    if((fr=fopen(subor,"r"))==NULL){
        printf("nepodarilo sa otvorit subor");
        return NULL;
    }
    else{
        fscanf(fr,"%d \n",nacitane);
        if((nacitane)==NULL){

            return NULL;
        }
        else{
            pole=cMemoryS(*nacitane);
            for(i=0;i<*nacitane;i++){
                checks=fgets(pole[i].priezvisko_meno,100,fr);
                if(atoi(pole[i].priezvisko_meno)){
                    free(pole);
                    return NULL;
                }

                pole[i].priezvisko_meno[strcspn(pole[i].priezvisko_meno, "\n")] = 0;
                fscanf(fr,"%d \n",&pole[i].rocnik);
                if(!fscanf(fr,"%f \n",&pole[i].priemer)){
                    free(pole);
                    return NULL;
                }




            }
        }
    }
    if(fclose(fr)==EOF){
        printf("nepodarilo sa zavriet subor");
    }
    return pole;
}
void vypisPole (STUDENT *studenti, int pocet){
    int i;
    for (i=0;i<pocet;i++){
        printf("%s;",studenti[i].priezvisko_meno);
        printf("%d;",studenti[i].rocnik);
        printf("%.2f \n",studenti[i].priemer);

    }

}
STUDENT *najlepsiPole (STUDENT *studenti, int pocet, int rocnik){
    int i;
    float best=5.0;
    STUDENT *naj;
    for(i=0;i<pocet;i++){
        if(studenti[i].rocnik==rocnik){
            if((studenti[i].priemer)<best){
                best=studenti[i].priemer;
                naj=&studenti[i];
            }
        }
    }
    return naj;
}

int main()
{
   STUDENT *pole, *naj;
   int pocet;
   pole = nacitajPole("vstup.txt", &pocet);
   if (pole == NULL) {
        printf("nepodarilo sa nacitat a naplnit pole");
        return -1;
   }
   vypisPole(pole, pocet);
   naj = najlepsiPole(pole, pocet, 3);
   if (naj == NULL) {
        printf("v rocniku nie je student");
        return -2;
    }
    printf("najlepsi student je %s", naj->priezvisko_meno);
    free(pole);
    return 0;
}
