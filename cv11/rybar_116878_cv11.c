
/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:11              */
/*=======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
    struct student *dalsi;
}STUDENT;
void uvolniSpajany (STUDENT *studenti){
    STUDENT *akt;
    while(studenti!=NULL){
        akt=studenti;
        studenti=studenti->dalsi;
        free(akt);
        akt=NULL;
    }

}

STUDENT *nacitajSpajany(char *subor){
FILE *fr;
STUDENT *zac,*akt;
int pocet,i;
if((fr=fopen(subor,"r"))==NULL){
    return NULL;
}
else{
    fscanf(fr,"%d \n",&pocet);
    if((zac=(STUDENT *)malloc(sizeof(STUDENT)))==NULL){
       printf("malo pamate");
       return NULL;
       }
    akt=zac;

    for(i=0;i<pocet;i++){
        akt->dalsi=NULL;
        fgets(akt->priezvisko_meno,100,fr);
        if(atoi(akt->priezvisko_meno)){
                    uvolniSpajany(zac);
                    return NULL;
                }
        akt->priezvisko_meno[strcspn(akt->priezvisko_meno, "\n")] = 0;
        fscanf(fr,"%d \n",&akt->rocnik);
        if(!fscanf(fr,"%f \n",&akt->priemer)){
            uvolniSpajany(zac);
            return NULL;
            }
        else if(akt->priemer>10.0||akt->priemer<1.0){
            uvolniSpajany(zac);
            return NULL;
        }
        if((akt->dalsi=(STUDENT*)malloc(sizeof(STUDENT)))==NULL){
            printf("malo pamate");
            return NULL;
            }
        akt=akt->dalsi;
        akt->dalsi=NULL;
        }
    return zac;
    }
}
void vypisSpajany (STUDENT *studenti){
    STUDENT *akt;
    akt=studenti;
    while(akt->dalsi!=NULL){
        printf("%s;%d;%.2f \n",akt->priezvisko_meno,akt->rocnik,akt->priemer);
        akt=akt->dalsi;

    }


}


int main(){
    STUDENT *spajany;

    spajany= nacitajSpajany("vstup.txt");
    if (spajany== NULL) {
        printf("nepodarilo sa nacitat a naplnit zoznam");
        return -1;
    }
    vypisSpajany(spajany);
    uvolniSpajany(spajany);
    return 0;
}
