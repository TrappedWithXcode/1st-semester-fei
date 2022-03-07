//
//  main.c
//  uloha3
//
//  Created by Marek Rybar on 12/10/2021.
//

#include <stdio.h>
int uloha1(){
    int i,j,k=0,num=1,m=0;
    float a=-1,b=0,av=0,max=-32768,sum=0;
    printf("zadajte pocet realnych cisiel:");
    scanf("%d",&i);
    for (j=0;j<i;j++) {
        printf("zadaj cislo cislo %d:",num++);
        scanf("%f",&a);
        if (a<0) {
            ++k;
            if (k==0) {
                av=0;

            }
            else{

                b=sum=a+b;

            }
            av=sum/k;



        }
        else if (a>=0){

                if(a>max){
                    max=a;
                }
        }
        if (-5.5<=a && a<=5.5) {
            m++;
        }
        getchar();
    };

    printf("priemer zapornych cisiel: %.3f \n",av);
    printf("najvacsie kladne cislo je:%.2f \n",max);
    printf("pocet cisiel v intervale<-5.5,5.5>:%d \n",m);
    return 0;
}
int uloha2(){
    int f,a,A,num;
    printf("napiste lubovolny retazec (a-z,A-Z,0-9): ");

    a=0;
    A=0;
    num=0;
    while ((f=getchar()) !='\n') {
        if (f>='a'&&f<='z') {
            ++a;
            continue;
        }
        else if (f>='A'&&f<='Z'){
            ++A;
        }
        else if (f>='0'&&f<='9'){
            ++num;
        }
    }
    printf("\n");
    printf("pocet malych pismen: %d \n",a);
    printf("pocet velkych pismen:%d \n",A);
    printf("pocet cisiel:%d \n",num);


    return 0;

}
int main() {
    uloha1();
    uloha2();
    return 0;
}
