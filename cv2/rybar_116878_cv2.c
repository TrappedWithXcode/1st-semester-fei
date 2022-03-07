

#include <stdio.h>
int uloha_1(){
    int a,b;
    
    printf("zadaj dve cele cisla oddelene medzerou \n");
    scanf("%d %d",&a,&b);
    (a>b)?printf("a) vacsie cislo zo zadanych je: %d \n",a)
        :printf("a) vacsie cislo zo zadanych je: %d \n",b);
    if (a<b)
        printf("b) mensie cislo zo zadanych je: %d \n",a);
    else
        printf("b) mensie cislo zo zadanych je: %d \n",b);
        
    return 0;
}
int uloha_2(){
    int c;
    printf("zadaj lubovolny jeden znak: \n");
    c=getchar();
   
    c=getchar();
    if ((c>='a')&&(c<='z')) {
        printf("zadany znak je: male pismeno \n");
    }
    else if ((c>='A')&&(c<='Z')){
        printf("zadany znak je: velke pismeno \n");
    }
    else if ((c>='0')&&(c<='9')){
        printf("zadany znak je: cislo \n");
    }
    else{
        printf("zadany znak je: inym znakom \n");
    }

      
        
    
    return 0;
}
int uloha_3(){
    int c;
   
    printf("zadaj jeden znak: \n");
    c=getchar();
  
    c=getchar();
    printf("znak '%c' na vstupe ma ASCI hodnotu: %d a %X v hexadecimalnom zapise \n",c,c,c);
    if ((c>='a')&&(c<='z')) {
        printf("male pismeno '%c' bolo zmenene na velke \n",c);
        c= c-'a'+'A';
        printf("znak '%c' na vstupe ma ASCI hodnotu: %d a %X v hexadecimalnom zapise \n",c,c,c);
    }
   
   
    return 0;
}
int main() {
    uloha_1();
    uloha_2();
    uloha_3();
    
    return 0;
}
