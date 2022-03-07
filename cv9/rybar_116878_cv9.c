/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:9               */
/*=======================================*/
#include <stdio.h>
#include <stdlib.h>
int **create(int riadky, int stlpce) {
    int **p, i;
    p = (int **) malloc(riadky * sizeof(int *));
    for(i = 0; i < riadky; i++)
        p[i] = (int *) malloc(stlpce * sizeof(int));
    return p;
}
int **AlokujNapln(int *riadky, int *stlpce){
    FILE *fr;
    int column,row,i,j,aux,check;
    int **p;

    if((fr=fopen("vstup.txt","r"))==NULL){
       printf("nepodarilo sa otvorit subor");
        return NULL;
    }
    fscanf(fr,"%d %d",&row,&column);
    p=create(row,column);
    if(p==NULL){
        printf("problem s alokaciou");
        return NULL;
    }
      for(i=0;i<column;i++){
        for (j=0;j<row;j++){
            check=fscanf(fr,"%d",&aux);
            p[i][j]=aux;
            printf("%d",p[i][j]);

        }
    }
    if(check!=1){
        printf("malo cisiel v matici \n");
        return NULL;
    }


    *riadky=row;
    *stlpce=column;
    return  p;


}

void Uvolni(int **pole, int riadky){
    int i;
    for (i=0;i<riadky;i++){
        free(pole[i]);
    }
    free(pole);
    pole=NULL;
}
void Vypis(int **pole, int riadky, int stlpce){
    int i,j;
    for(i=0;i<stlpce;i++){
        for(j=0;j<riadky;j++){
            printf("%5d ",pole[i][j]);
        }
        printf("\n");
    }
}
int NajdiMax(int **pole, int riadky, int stlpce,int *riadok,int *stlpec){
    int i,j,max=0,maxi=0,maxj=0;
    for(j=0;j<stlpce;j++){
        for(i=0;i<riadky;i++){
            if(pole[i][j]>max){
                max=pole[i][j];
                maxi=i;
                maxj=j;
            }
        }
    }
    *riadok=maxi;
    *stlpec=maxj;
    return max;
}

int main() {
    int **pole;
    int riadky,stlpce, max, max_riadok, max_stlpec;
    pole = AlokujNapln(&riadky, &stlpce);
    if (pole == NULL) {
            printf("Pole sa nepodarilo naplnit");
            return 1;
            }
            Vypis(pole, riadky, stlpce);
            max = NajdiMax(pole, riadky, stlpce, &max_riadok, &max_stlpec);
            printf("Maximum pola [%d] sa naslo na suradnici [%d, %d]", max, max_riadok, max_stlpec);
            Uvolni(pole, riadky);
            return 0;


}


