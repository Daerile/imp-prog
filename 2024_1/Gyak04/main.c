#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void betuOlvasas();
int osszead(int a, int b, bool logikai);

int main(){

    // 1. feladat

    // i++
    int a = 5;
    int b = 3;
    int b2 = 3;
    int c = a + (b + 1); // 9
    printf("b = %i\n", b);
    int d = a + (b++); // 8 -> b = 4
    printf("b = %i\n", b);
    int e = a + (++b2); // 9 -> b = 4
    printf("_ = %i, b++ = %i, ++b = %i\n", c,d,e);

    int i;
    for(i = 0; i < 10;){
        printf("%i\n", ++i);
    }

    // 2. feladat
    // betuOlvasas();

    // Metódusok
    printf("\n\n\n");
    printf("3 + 5 = %i\n",osszead(3,5,true));
    int eredmeny = osszead(3,5,false);
    printf("Eredmeny = %i", eredmeny);

    return 0;
}

int osszead(int a, int b, bool logikai){
    int sum;
    if(logikai == true){
        sum = a + b;
        return sum;
    }else{
        sum = a - b;
        return sum;
    }
    // return sum;
}

void betuOlvasas(){
    // #include <ctype.h>
    char c;
    // int szamlalo = 0;
    do{
        scanf(" %c", &c);
        // szamlalo++;
        if(!isalpha(c)){
            printf("Nem jo\n");
        }else{
            printf("Beolvasott = %c\n", c);
            if(isupper(c)){
                c = tolower(c);
            }else{
                c = toupper(c);
            }
            printf("Atalakitott = %c\n", c);
        }
    }while(c != EOF);
}