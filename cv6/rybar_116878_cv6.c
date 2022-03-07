/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:6               */
/*=======================================*/


#include <stdio.h>
#include <string.h>
#define N 300

void uloha01(){
    char pole[N],a;
    long b,i,j;


    printf("nacitaj retazec: ");
    gets(pole);
    b=strlen(pole);
    if (b==0) {
        printf("prazdne pole \n");
        return;
    }
    else if (b==1){
        printf("obratene pole bude rovnke ako zadane. \nHodnota je: ");
        puts(pole);
        printf("\n");
        return;
    }
    for (i=0,j=b-1;i<j; i++,j--) {
        a=pole[i];
        pole[i]=pole[j];
        pole[j]=a;
    }
    printf("obratene pole je: ");
    puts(pole);




}
void uloha2(){
    char arr[500],a;
    printf("zadajte retazec na upravu: ");

    long doc,k,i=0,j,l=1,n=0;
    gets(arr);
    doc=strlen(arr);
    //printf("%d \n",doc);
    if (doc==0) {
        printf("nebol nacitany retazec \n");
        return;
    }

    while (arr[i]!='\0') {

         if (arr[i]==' ') {

            for (j=i; j<doc; j++) {
                arr[j]=arr[j+1];
            }
        }
        if(arr[i]>='0'&&arr[i]<='9'){
            n++;
            arr[doc+n]='\n';
            arr[doc]=arr[doc+1];
            for (k=doc; k>=i; k--) {

                a=arr[k];
                arr[k+1]=a;
            }
            arr[i]='.';
            arr[i+1]='.';
        }
        i++;
}
    printf("upraveny retazec je: ");

    puts(arr);
    printf("\n");

}

void uloha3(){
    FILE *fw,*fr;
    char c1,c2;
    int ent=1;
    fr=fopen("vstup.txt","r");
    fw=fopen("vystup.txt","w");

    if (fr==NULL){
        printf("subor na citanie sa nepodarilo otvorit");
        return;
    }
     if (fw==NULL){
        printf("subor na zapisovanie sa nepodarilo otvorit");
        return;
    }


    while ((c1=fgetc(fr))!=EOF){

            if (ent%2!=0){
                    if(c1<='9'&&c1>='0' ){
                        c1='*';
                        putc(c1,fw);
                    }
                    else{
                        putc(c1,fw);
                    }
                }
            if(ent%2==0){
                if((c1>='a'&&c1<='z')||(c1>='A'&&c1<='Z')){
                    c1='-';
                    putc(c1,fw);
                }
                else{
                    putc(c1,fw);
                }
            }
            if (c1=='\n'){
                ent++;
            }


    }
    if(fclose(fr)==EOF){
            printf("nepodarilo sa zatvorit subor vstup.txt \n");
        }
    if(fclose(fw)==EOF){
            printf("nepodarilo sa zatvorit subor vystup.txt \n");
        }
}

int main() {
    uloha01();
    uloha2();
    uloha3();
    return 0;
}
