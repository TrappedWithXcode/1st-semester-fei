/*======================================*/
/*   Rybár,Marek, osobné číslo: 116878  */
/*           Cvičenie 1                 */
/*           23.9.2021                  */
/*======================================*/

#include <stdio.h>

int cv1_prvy(){
    //riesenie
    printf(" \" \t su vsetky tieto [*,&,/,\\,$,%%,\'] znaky specialne \?\" \n" );
    
    return 0;
}
int cv1_druhy(){
    int a,b,c,s,V;
    
    printf("vlozte tri cisla(cele)-oddelene medzerou: ");
    scanf("%d %d %d", &a,&b,&c);
    
    V = a*b*c;//vypocitanie objemu
    s = 2*a*b+2*b*c+2*a*c;//vypocitanie povrchu
    
    printf("objem %d x %d x %d je: %d \n",a,b,c,V);
    printf("povrch 2 x %d x %d + 2 x %d x %d + 2 x %d x %d je: %d \n",a,b,b,c,a,c,s);
    
    return 0;
}
int cv1_treti(){
    float r,pi,s,C;
    pi=3.1415;
    
    printf("zadajte polomer(realne cislo): ");
    scanf("%f",&r);
    
    C= 2*pi*r; //obvod kruznice
    s= pi*r*r; //obsah kruznice
    
    printf("pre polomer: %.2f je obvod: %.2f a obsah: %.2f \n ", r,C,s);
    
    return 0;
}

/*-------------------------------*/
/*priklady na hlbkove precvicenie*/
/*-------------------------------*/
int hlbkove_jedna(){ //hlbkove precvicenie1
    float x,y,z,p;
        
    printf("zadajte 3 realne cisla oddelene medzerou: ");
    scanf("%f %f %f",&x,&y,&z);
   
    p = (x+y+z)/3; //vypocitanie priemeru
    
    printf("pre cisla: %.2f, %.2f, %.2f je priemer: %.2f\n ", x,y,z,p);
    
    return 0;
}

int hlbkove_dva(){//hlbkove precvicenie2
    float x,y,tax,tax_percentage;
    
    tax=0.2; //premenna pre dan
    tax_percentage=tax*100; // dan v percentach
    
    printf("zadajte lubovolne cislo: ");
    scanf("%f",&x);
    
    y=x+(x*tax);//vypocitanie dane
    
    printf("cena bez dane: %.2f, cena s danou %.0f%%: %.2f\n ", x,tax_percentage,y);
    
    return 0;
}
int hlbkove_tri(){//hlbkove precvicenie3
    float x,y,x_in_m,bmi;
    
    printf("zadajte hmotnost(kg): ");
    scanf("%f",&y);
    printf("zadajte vysku(cm): ");
    scanf("%f",&x);
    
    x_in_m= x/100; //premena cm na m
    bmi=y/(x_in_m*x_in_m); // vypocitanie bmi
    
    printf("pre vysku: %.2f cm a hmotnost: %.2f kg, BMI: %.2f \n", x,y,bmi);
    
    return 0;
}

int main() {
    
    cv1_prvy();
    cv1_druhy();
    cv1_treti();
    
    
    /*---------------------*/
    /* hlbkove precvicenie */
    /*-- (v komentaroch)---*/
    /*---------------------*/
    //hlbkove_jedna();
    //hlbkove_dva();
    //hlbkove_tri();
    

    return 0;
}

