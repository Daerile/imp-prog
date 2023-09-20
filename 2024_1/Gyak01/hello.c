#include <stdio.h>

int main(){
    printf("Hello World!\n");

    // int | double | float | char 
    // egész számok | valós számok | nagyobb valós számok | karakter
    // int a;
    float a = 10;
    float b = 3;
    float c = a / b;
    printf("A ket szam osszege: %f, a ket szam hanyadosa: %.2f\n", a + b, c);

    int alma = 5; // irunk a memóriába
    scanf("%d", &alma); // ugyanoda írunk, felülírunk
    printf("Alma erteke: %i", alma);
    return 0;
}