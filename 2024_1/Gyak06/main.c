#include<stdio.h>

int sum(int tomb[], int hossz);
int sum2(int* tomb, int* utolsoUtani);
float atlag(int* tomb, int* utolsoUtani);
void melyikKisebb(int* egyik, int* masik);


int main(){
    // & - referencia | &a - a változó memóriacímét kapjuk meg
    // * - dereferencia | *a (a memóriacím) - 
    // memóriacímen található változó értékét
    int a = 5;
    printf("a = %i\n", a);
    int* pint = &a;
    // int *pint2 = &a; // ugyanaz a kettő
    printf("a memoriacime = %p\n", pint);
    printf("a = %i\n", *pint);

    // 1. feladat
    *pint = 3; // a memóriacím marad, viszont az érték változik
    printf("a = %i\n", *pint);
    int b = 10;
    pint = &b; // a memóriacím változik
    *pint = 1;
    printf("a = %i, b = %i\n", *&*&*&*&a,b);

    // 2. feladat
    int** ppint = &pint;
    int c = -5;
    *ppint = &c;
    b = 20;
    c = 40; // ez fog változást előidézni a printben
    printf("*pint = %i\n", *pint);
    **ppint = 420;
    printf("c = %i\n", c);

    // 3. feladat
    // printf("int* = %d, char* = %d, float* = %d", sizeof(int*), sizeof(char*), sizeof(float*));
    // void - magára mutató pointer

    // 4. feladat
    int tomb[5] = {3,7,-2,20,13};
    printf("sum = %i\n", sum(tomb, 5));
    printf("sum2 = %i\n", sum2(tomb, tomb + 5));
    printf("atlag = %f\n", atlag(tomb, tomb + 5));

    // c-ben int tomb[]

    // 8. feladat
    // char* pnull = NULL;
    // char* pchar;
    // printf("*pchar = %c\n", *pchar);
    // printf("*pnull = %c\n", *pnull);
    // nem működik
    

    // 10. feladat
    melyikKisebb(tomb, tomb + 2);
    melyikKisebb(tomb + 3, tomb + 1);
    melyikKisebb(tomb + 2, tomb + 2);
    return 0;
}

void melyikKisebb(int* egyik, int* masik){
    // int tav = egyik - masik;
    if(egyik < masik){
        printf("Az elso hamarabb van\n");
    } else if(egyik > masik){
        printf("A masodik hamarabb van\n");
    } else{
        printf("Ugyanarra az indexre mutatnak\n");
    }

}

float atlag(int* tomb, int* utolsoUtani){
    float sum = 0;
    // float db = 0;
    int db = utolsoUtani - tomb;

    while(tomb != utolsoUtani){
        sum += *tomb;
        tomb += 1;
        // db++;
    }
    printf("db = %i\n", db);
    return sum / db;
}

int sum2(int* tomb, int* utolsoUtani){
    int sum = 0;
    // while(tomb != utolsoUtani + 1){
    //     sum += *tomb;
    //     tomb += 1;
    // }
    
    int i = 0;
    printf("pointer = %p, int = %i\n", utolsoUtani, *utolsoUtani);
    while((tomb + i) != utolsoUtani + 1){
        sum += *(tomb + i);
        i++;
    }
    return sum;
}

// int tomb[] == int* tomb -> első elemre mutat
int sum(int* tomb, int hossz){
    int sum = 0;
    int i;
    // printf("elso elem = %i\n", *tomb);
    // printf("masodik elem = %i\n", *(tomb + 1));
    for(i = 0; i < hossz; i++){
        sum += *(tomb + i);
    }
    return sum;
}