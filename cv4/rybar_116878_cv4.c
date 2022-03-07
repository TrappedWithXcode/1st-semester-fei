#include <stdio.h>
#include <stdlib.h>
/*======================================*/
/*   Rybár,Marek, osobné èíslo: 116878  */
/*           Cvièenie 4                 */
/*           19.10.2021                 */
/*======================================*/

#include <stdio.h>
int uloha1(){
    FILE *fw;
    int i,j,n,a=1;
    printf("zadajte cele cislo medzi 1-10:");
    scanf("%d",&n);
    if(n>=1 && n<=10){
    fw=fopen("floyd.txt", "w");
    for (i=1; i<=n; i++) {
        for (j=1;j<=i; j++) {
            if(i>=j){
                fprintf(fw,"%d ",a++);
            }
            else
                fputc(' ',fw);
        }
        fputc('\n',fw);
    }
    fclose(fw);

    return 0;
    }
    else{
        printf("nespravne zadany vstup\n\n");
    }
    return 0;
}

int uloha2(){
    FILE *fr;

    int i,j,a,b;

    if(fr=fopen("rozmery.txt", "r")){

    fscanf(fr,"%d %d\n",&a,&b);
    printf("pre vstup:%d a %d\n",a,b);
    for(i=1;i<=a;i++){
        printf("%d :",i);
        for(j=b;j>=1;j--){
            if(i<=b&&j>=i)
            putchar('*');
            }


        putchar('\n');
    }
    printf("koniec opacneho trojuholnika\n");
    fclose(fr);
    return 0;
    }
    else{
        printf("subor neexistuje alebo je zle pomenovany");
    }
    return 0;
}
int main() {

    uloha1();
    uloha2();
    return 0;
}
