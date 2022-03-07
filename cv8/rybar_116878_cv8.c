/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:8               */
/*=======================================*/


#include <stdio.h>
#include <stdlib.h>
int NacitajMaticu(char *subor,int m[10][10]){
    FILE *fr;
    int i=0,j=0,num=-1,spce=0,entr=0;
    int c;
    fr=fopen(subor,"r");
    if(fr==NULL){
        printf("Subor pravdepodbne neexistuje");
        return 0;
    }
    printf("program rata ze za poslednym cislom nie je medzera \n");
    while((c=getc(fr))!=EOF){

        if(c==' '){
            spce++;
        }
        if(c=='\n'){
            entr++;
        }



        }
        if(spce>90){
                printf("Privela znakov \n");
                return 0;
                exit(0);
        }
        if(spce<90){
            printf("prilis malo znakov \n");
            return 0;
            exit(0);

        }
        if(entr<9){
            printf("prilis malo znakov");
        }

    fseek(fr,0,SEEK_SET);
    for(j=0;j<10;j++){
        for(i=0;i<10;i++){
            fscanf(fr,"%d",&num);
            m[i][j]=num;
            }
       }
       if(fclose(fr)==EOF){
            printf("nepodarilo sa zatvorit subor %s \n",*subor);
        }
       return 1;

}

int AnalyzujMaticu(int m[10][10],int *zaporne,int *neparne){
   int i,j, zap=0,nepa=0,maxim=0,compare;
    for (j=0;j<10;j++){
        for(i=0;i<10;i++){
                compare=m[i][j];
                if(m[i][j]<0){
                    zap++;
                }
                if(m[i][j]%2!=0){
                    nepa++;
                }
                if(compare>maxim){
                    maxim=compare;
                }



        }
    }
    *zaporne=zap;
    *neparne=nepa;
    return maxim;
}
int VypisMaticu(int m[10][10]){
    int i,j;
    for(j=0;j<10;j++){
        for(i=0;i<10;i++){
            printf(" %5d ",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m[10][10], zaporne, neparne, max;
    if (NacitajMaticu("vstup.txt", m)) {
            max = AnalyzujMaticu(m,&zaporne,&neparne);
            VypisMaticu(m);
            printf("zaporne: %d, neparne: %d, maximum: %d", zaporne, neparne, max);}
    else printf("citanie sa nepodarilo");
   return 0;
}
