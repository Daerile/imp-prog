#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// int number2;

int main(){
    int number;
    float valFloat;
    static char valChar; // \0
    if(valChar == '\0'){
        printf("Igen nulla\n");
    }
    printf("int = %i, float = %f, char = %c\n\n", number, valFloat, valChar);

    scanf("%d", &number);
    if(number % 2 == 0){
        printf("The number %d is even\n", number);
    }else{
        printf("The number %d is odd\n", number);
    }

    if(number < 0){
        printf("Negative\n");
    }else if (number > 0){
        printf("Positive\n");    
    }else{
        printf("Zero\n");
    }
    printf("\n");

    float testFloat = 3.123123;
    double testDouble = -5.3231;
    char testChar = '\n';
    bool testBool = true;
    // típus név [elemek száma]
    char stringTest [5] = {'h','e','\0','l'};

    int i1 = testFloat;
    int i2 = testDouble;
    int i3 = testChar;
    int i4 = testBool;
    // int i5 = stringTest;
    printf("%i\n", stringTest[4] == '\0');
    printf("string = %s\n", stringTest);
    printf("float = %d, double = %d, char = %d, bool = %d, string = %d\n", i1, i2, i3, i4);

    int valami = sizeof(int);
    printf("sizeof int = %d\n", sizeof(long long unsigned int));
    // int = 4 byte = 32 bit 2^(32-1) - 1
    long long unsigned int maxInt = pow(2, sizeof(long long unsigned int)*8 - 1) - 1;
    printf("maxInt = %I64d\n", maxInt - 1);

    float a;
    float b;
    scanf("%f", &a);
    scanf("%f", &b);
    printf("%f es %f atlaga = %f\n", a, b, (a + b) / 2);

    // for while do-while
    int i;
    int sum = 0;
    for(i = 0; i < 21; i++){
        sum = sum + i;
        // sum += i;
    }

    // while(sum > 300){
    //     sum -= 3;
    //     printf("sum = %d\n", sum);
    // }

    do{
        sum -= 3;
        printf("sum = %d\n", sum);
    }while(sum > 300);

    printf("20 ig a szamok osszege = %d", sum);
    return 0;
}