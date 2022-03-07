/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:7               */
/*=======================================*/

#include <stdio.h>
#include <string.h>
int i=0,j=0;
while(i!=9&&j!=9){
    if(i==9){
        j++;
        i=0;
        printf("\n");
    }
    printf("%d",m[i][j]);

}
/*int NacitajMaticu(char *subor,int m[10][10]){
    FILE *fr;
    int i=0,j=0,k=0,l=0,num=-1,num2,spc=0,ent=0;
    char check;
    fr=fopen(subor,"r");
        for(j=0;j<10;j++){
            for(i=0;i<10;i++){

                fscanf(fr,"%d",&num);

                m[i][j]=num;
                num=-2147483647;

        }

       }


    for(l=9;l>=0;l--){
            for(k=9;k>=0;k--){
                if (m[k][l]==-2147483647){
                    printf("malo prvkov v matici \n");
                    return 0;
                }



            }
    }






return 1;




}*/
#define N 100
char *sprava;
char*sifruj(char*sprava,char*heslo){
    int dlzkaSprv=strlen(sprava),dlzkaHsl=strlen(heslo),i,j=0,vypocet=0,posunutie=0,a,b;

    for (i=0; i<dlzkaSprv; i++) {
        if (j==dlzkaHsl) {
            j=0;
        }
        a=(int)heslo[j];
        vypocet=a-'A';
        posunutie=vypocet+1;
        sprava[i]=sprava[i]+posunutie;
        if (sprava[i]+posunutie>'Z') {
            b=sprava[i]-'Z';
            sprava[i]='A'+b-1;
        }

        j++;

    }

    return sprava;
}
int analyzuj(char *subor, int *riadky, int *medzery, int *cisla){
    FILE *fr;
    char c;
    int ent=1,spc=0,nmr=0,lttr=0,othrs=0,velkost=0;

    fr=fopen(subor,"r");
    if(fr==NULL){
    return-1;
    }
    else{

    while((c=fgetc(fr))!=EOF) {
        if (c=='\n'){
            ent++;
        }
        if(c==' '){
            spc++;
        }
        if(c<='9'&&c>='0'){
            nmr++;
        }
        if(c>='A'&&c<='Z'){
            lttr++;
        }
        if(c>='a'&&c<='z'){
            lttr++;
        }
    }
    *riadky=ent;
    *medzery=spc;
    *cisla=nmr;

    velkost=(ent+spc+nmr+lttr+othrs);
    fclose(fr);
    return velkost;
    }
}

int main(){
/*priklad1 -----------*/
    char a[N],b[N];
    printf("zadajte text na sifrovanie: ");
    gets(a);
    printf("zadajte heslo/kluc sifrovania: ");
    gets(b);
    printf("\n");
    printf("vystup sifrovania : %s \n",sifruj(a,b));


/*priklad3------------*/
    int riadky, medzery, cisla, velkost;
    velkost = analyzuj("vstup.txt", &riadky, &medzery, &cisla);
    if (velkost == -1) printf("subor sa nepodarilo otvorit!");
    else printf("subor ma velkost %d, pocet riadkov %d, medzery: %d a cisla%d",  velkost, riadky, medzery, cisla);

    return 0;

}
