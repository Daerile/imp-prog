#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define VALAMI 10

// <visszatérési érték> <név> (<paraméterek>){ ... }
// void = nincs visszatérési érték

int valami2; // 0 az értéke

void byteErtekek(){
    printf("%I64i %I64i %I64i %I64i\n", sizeof(int), sizeof(long int), sizeof(unsigned int),sizeof(unsigned long int));
    printf("%i %i %i %i %i\n", sizeof(char), sizeof(_Bool), sizeof(float),sizeof(double), sizeof(long double));
}

void operatorChaining(){
    if(3 < 5 == 4 > 3){ // 3 < 5? = igaz | igaz > 4 | 1 > 4
        printf("Igaz\n");
    }else{
        printf("Hamis\n");
    }
}

void legnagyobbUInt(){
    unsigned int legnagyobb = pow(2, sizeof(unsigned int) * 8) - 1;

    printf("%u\n", legnagyobb);
}

void szokoevE(){
    int evszam;
    scanf("%i", &evszam);

    // &&-és || - vagy
    bool vizsgalo = (evszam % 4 == 0 && evszam % 100 != 0) || evszam % 400 == 0;
    // <feltétel> ? <igaz esetén> : <hamis esetén>
    printf("%i %sszokoev\n", evszam, vizsgalo ? "" : "nem ");
}

int main(){
    
    byteErtekek();
    const int valami; // 0 az értéke
    printf("%i\n", VALAMI);

    operatorChaining();

    legnagyobbUInt();

    szokoevE();

    // Bekérünk egy számot és műveletek végzünk el rajta egy másik számmal
    // 0 = nem csinálunk semmit
    // 1 = duplázzuk
    // 2 = hozzáadunk 100at
    // 3 = felezzük
    // 4 = másodikra emeljük
    
    int szam;
    int vezerlo;
    scanf("%i", &szam);
    scanf("%i", &vezerlo);

    int eredmeny = 0;
    
    switch(vezerlo){
        case 0:
            eredmeny = szam;
            break;
        case 1:
            eredmeny = szam * 2;
            break;
        case 2:
            eredmeny = szam + 100;
            break;
        case 3:
            eredmeny = szam / 2;
            break;
        case 4:
            eredmeny = pow(szam,2);
            break;
        default:
            eredmeny = -1;
            break;
    }
    printf("%i", eredmeny);
    return 0;
}