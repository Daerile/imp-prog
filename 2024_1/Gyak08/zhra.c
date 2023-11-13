// includeok, amik kellhetnek

#include <stdio.h> // Input olvasás, output írás.
#include <stdbool.h> // bool változótípus
#include <math.h> // Matematikai függvények, értékek pl. pow
#include <ctype.h> // Karakterkezeléshez hasznos függvények toupper(), isupper() ...

// Random szám generálásához:
#include <time.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10


void kiirat(char* szoveg, int n);
int main(){
    
    // Mit kell tudni:

    // 1. óra
    /*
    Alaptípusok: int, float, double, char, bool
    Inicializálni, deklarálni ezeket.
    Kiiratás: printf(), beolvasás: scanf()
    Ezekhez a megfelelő type specifier (pl %i, %c, ...) alkalmazása
    printf() - el formázás.
    */

    // 2. óra
    /*
    ciklusok: for, while, dowhile
    static kulcsszó: az inicializálástól végig benne van a program életciklusában
    if - else elágazások
    sizeof() értése és használata
    char[]: String, végén '\0' (null) karakter
    */

    // 3. óra
    /*
    makrók
    switch case
    unsigned kulcsszó: szám változók, ahol nincs - érték, emiatt 2* annyi + van.
    <, >, ==, /=, &&, || operátorok
    random szám generálás
    */

    srand(time(NULL));
    // 0-től n ig
    // 0 - 17 ig

    // 3 - 17 ig -> // 0 - 14 + 3 
    int randomSzam = (rand() % 15) + 3;

    // -2 - 5 ig -> 0 - 7 ig
    int randomSzam2 = (rand() % 8) - 2;

    // 4. óra
    /*
    függvények különböző visszatérési értékekkel és paraméterekkel
    ctype.h segítségével: karakterfüggvények ismerete
    getchar()
    EOF-ig olvasás -- 7. gyakorlat anyagában helyesen van.
    */

    char bejovo;
    while((bejovo = getchar()) != EOF){
        printf("Beolvasott = %c\n", bejovo);
        getchar();
    }
    // 5. óra
    /*
    tömbök
    */

    // 6. óra
    /*
    pointerek
    tömbök pointer aritmetikával, miért jó, stb...
    */

    int n = 5;
    char szoveg[] = {'a','l','m','a','\0'}; // ez oké
    // char szoveg2[n]; // ez oké, hiába aláhúzza
    char szoveg3[WIDTH]; // ez oké
    // char szoveg3[n] = {'a','l','m','a','\0'} // nem jó
    
    kiirat(szoveg, n);

    // 7. óra
    /*
    kétdimenziós tömbök
    ennek a pointer aritmetikája
    */

    int m = 0;
    int i;
    int tomb[3][3];

    // külön fv-ben
    for(i = 0; i < n; i++){
        int j = 0;
        for(j = 0; j < m; j++){
            printf("%i ", *((tomb + i * m) + j));
            *((tomb + i * m) + j) = 0;
        }
    }

    // *((tomb + i * m) + j)


    return 0;
}

// char* szoveg === char szoveg[]
// [] = *
void kiirat(char* szoveg, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%c", *(szoveg + i));
    }
}