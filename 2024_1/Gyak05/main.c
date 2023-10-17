#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

void kiirat(int tomb[], int meret);
int sum(int tomb[], int meret);
int max(int tomb[], int meret);
int masodikMin(int tomb[], int meret);
void abcSorrend(char string[], char string2[], int m1, int m2);
int stringHossz(char string[]);

int main(){
    int meret = 5;
    int enTombom[5] = {4,2,7,4,1};
    // enTombom[3]; // == 4
    // <típus> <név>[<méret>]; deklarálás, nem tudjuk hogy mi van benne
    // <típus> <név>[5] = {<értékek>}, inicializálás is 
    // tömb bejárása
    // kiirat(enTombom, meret);
    kiirat(enTombom, meret);
    // for(i = 0; i < meret; i++){
    //     printf("%i ", enTombom[i]);
    // }
    // printf("\n");

    // 1. feladat
    int adottMeret = 10;
    int nullaTomb[adottMeret];
    int i;
    for(i = 0; i < adottMeret; i++){
        nullaTomb[i] = 0;
    }
    kiirat(nullaTomb, adottMeret);

    // 2. feladat
    printf("A tombben a szamok osszege = %i\n", sum(enTombom,meret));

    // i = 1;
    // switch(i){
    //     case 0:
    //         printf("alma");
    //         break;
    //     case 1:
    //         printf("barack");
    // }

    // 3. feladat
    printf("A maximum elem = %i\n", max(enTombom,meret));

    // 4. feladat
    printf("Masodik min = %i\n", masodikMin(enTombom, meret));

    // 7. feladat
    char elso[5] = {'a','l','m','a'};
    char masodik[5] = {'b','o','c','i'};
    char harmadik[6] = {'a','l','m','a','a'};

    abcSorrend(elso,elso,5,5);
    printf("A tomb hossza = %i\n",stringHossz(harmadik));
    return 0;
}

int stringHossz(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

void kiirat(int tomb[], int meret){
    int i;
    for(i = 0; i < meret; i++){
        printf("%i ", tomb[i]);
    }
    printf("\n");
}

int sum(int tomb[], int meret){
    int result = 0;
    int i;
    for(i = 0; i < meret; i++){
        result += tomb[i];
    }
    return result;
}

int max(int tomb[], int meret){
    // int result = INT_MAX; legkisebb lehetséges érték
    int result = tomb[0];
    int i;
    for(i = 1; i < meret; i++){
        if(result < tomb[i]){
            result = tomb[i];
        }
    }
    return result;
}

int masodikMin(int tomb[], int meret){
    int min2 = INT_MAX;
    int min = INT_MAX;
    int i;
    for(i = 0; i < meret; i++){
        if(min > tomb[i]){
            min2 = min;
            min = tomb[i];
        } else if(min2 > tomb[i]){
            min2 = tomb[i];
        }
    }
    return min2;
}

void abcSorrend(char string[], char string2[], int m1, int m2){
    
    int m;
    if(m1 < m2){
        m = m1;
    }else{
        m = m2;
    }
    
    bool voltEredmeny = false;
    int i;
    for(i = 0; i < m; i++){
        if(tolower(string[i]) < tolower(string2[i])){
            printf("Az elso string hamarabb van az abc-ben\n");
            voltEredmeny = true;
            break;
        } else if(tolower(string[i]) > tolower(string2[i])){
            printf("Az masodik string hamarabb van az abc-ben\n");
            voltEredmeny = true;
            break;
        }
    }

    if(!voltEredmeny){
        printf("Ugyanaz a string\n");
    }
}
