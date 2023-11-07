#include<stdio.h>
#include<ctype.h>

const int nT = 3;
const int mT = 5;

void kiirat2(int* tomb, int n, int m);
void kiirat3(int tomb[nT][mT]);

int main(){
    int hexa[100];
    int guard = 0;
    char bejovo;
    // int res;
    // while(bejovo != EOF){
    //     res = scanf("%c", &bejovo);
    //     printf("Beolvasott = %c\n", bejovo);
    // }

    printf("%i\n", '0'); // 48 -> 0   | -48
    printf("%i\n", 'a'); // 97 -> 10  | -87
    while((bejovo = getchar()) != EOF){
        printf("Beolvasott = %c\n", bejovo);
        getchar();
        bejovo = tolower(bejovo);
        if(bejovo - 48 < 10){
            hexa[guard] = bejovo - 48;
            guard++;
        }else if(9 < bejovo - 87 && bejovo - 87 < 16){
            hexa[guard] = bejovo - 87;
            guard++;
        }else{
            printf("Nem jo karakter!\n");
        }
    }
    int i;
    for(i = 0; i < guard; i++){
        printf("%i ", *(hexa + i));
    }
    printf("\n");

    // n sor, m oszlop
    int ketdim[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // {
    // {1, 2, 3}
    // {4, 5, 6}
    // {7, 8, 9}
    // }
    kiirat2(ketdim, 3, 3);

    int n = 3;
    int m = 5;
    int peldaKetdim[n][m];
    int db = 0;
    for(i = 0; i < n; i++){
        int j;
        for(j = 0; j < m; j++){
            peldaKetdim[i][j] = ++db;
        }
    }

    kiirat2(peldaKetdim, n, m);
    kiirat3(peldaKetdim);

    return 0;
}

void kiirat3(int tomb[nT][mT]){
    int i;
    for(i = 0; i < nT; i++){
        int j = 0;
        for(j = 0; j < mT; j++){
            printf("%i ", tomb[i][j]);
        }
        printf("\n");
    }
}

void kiirat2(int* tomb, int n, int m){
    int i;
    for(i = 0; i < n; i++){
        int j = 0;
        for(j = 0; j < m; j++){
            printf("%i ", *((tomb + i * m) + j));
            // *((tomb + i * m) + j) = (i + 1) * (j + 1);
        }
        printf("\n");
    }

    for(i = 0; i < n * m; i++){
        // printf("%i ", *(tomb + i));
        if(i % m == 0){
            printf("\n");
        }
    }
    printf("\n");
}
