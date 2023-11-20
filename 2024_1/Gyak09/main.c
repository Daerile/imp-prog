#include <stdio.h>
#include "fuggvenyek.h"

int testKivul = 5;

int kiirat(){
    printf("Valami\n");
    printf("%i\n", testKivul);
    // char valami = 'a';
    return 1;
}
int main(){
    char snake[100];
    int returnValue = scanf("%s", snake);
    if(returnValue == EOF){
        printf("%i\n", returnValue);
        printf("Vege\n");
    }else{
        printf("%i\n", returnValue);
        printf("%s\n", snake);
    }
    // int eredmeny = kiirat();

    // ------------------------------------
    testKivul = 20;
    printf("%i\n", testKivul);
    // valami = 'c';

    {
        // int nemlatszik = 5;
        {
            // char blablabla = 'c';
            // nemlatszik = 10; // oke
        }
        // blablabla = 'a'; // nem oke
    }
    int nemlatszik = 6; // oké 

    // for(;;){}
    if((nemlatszik = 10) == 10){
        printf("%i\n", nemlatszik);
    }
    printf("%i\n", triplazo(nemlatszik));
    printf("-------------------------\n");
    staticTest();
    staticTest();
    staticTest();
    staticTest();
    a = 5;
    return 0;
}

void staticTest(){
    static int a = 0;
    a++;
    printf("%i\n", a);
}
