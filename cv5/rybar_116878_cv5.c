/*=======================================*/
/*   Marek, Rybar, osobne cislo: 116878  */
/*              cvicenie:5               */
/*=======================================*/

#include <stdio.h>
#define N 100
#define FILEOUT "vystup.txt"
#define FILEIN "cisla.txt"
int uloha1(){
    FILE *fw;
    int z;
    fw = fopen(FILEOUT,"w");
    printf("vlozte rozny retazec pre ukoncenie vkladania pouzit '.' \n"
            "na prejdenie na druhy riadok pozit enter -vas retazec: ");
    while((z=getchar())!='.'){

        if(z!='.'){
            if(z<='Z'&&z>='A'){
                fprintf(fw,"%c",z=z+('a'-'A'));
            }
            else if(z<='z'&&z>='a'){
                fprintf(fw,"%c", z='.');
            }
            else if (z>='0'&&z<='9'){
                fprintf(fw,"%c",z='-');
            }
            else if(z=='\n'){
                fprintf(fw,"%c",z='\n');
                printf("vlozte dalsi riadok retazca: (pre ukoncenie slucky stlacte '.')");
            }
            else{
                fprintf(fw,"%c",z='*');
            }


        }

        else{

            break;
        }

    }
    printf("\n");
    return 0;
}
int uloha2(){


    FILE *fr;
    fr = fopen(FILEIN,"r");

    int a[N];
    int i;

    if (fr == NULL){
        printf("Nenasiel sa subor");
        exit (0);
    }
    else {
        for (i = 0; i < N; i++){
            a[i]=0;

        }

        for (i = 0; i < N; i++){
            fscanf(fr, "%d,", &a[i] );

        }

        for (i = N-1; i >= 0; i--){
            if((a[i]!=0)&&(a[i]%2==0)){
                printf("%d ", a[i]);
            }

        }
        if (a[1]==0){
                printf("%d",a[1]);
            }


        if(fclose(fr)==EOF){
            printf("nepodarilo sa zatvorit subor \n");
        }
    }



    return 0;


}
int main( ) {
    uloha1();
    uloha2();
    return 0;
}
