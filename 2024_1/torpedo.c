#include <stdio.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

void init(int table[][HEIGHT], int placed_boats[]);
void printTable(int table[][HEIGHT]);
void submit(int table[][HEIGHT], int placed_boats[], bool direction, char x_char, int y, int length);
bool meret_check(int placed_boats[], int length);
bool lelogas_check(int x_cords[], int y_cords[], int length);
bool erintkezes_check(int x_cords[], int y_cords[], int length, int table[][HEIGHT]);
void elhelyezes(int table[][HEIGHT], int x_cords[], int y_cords[], int length);

int main(){
    int table[WIDTH][HEIGHT];
    // 4 hely, 2,3,4 és 5 hosszú elhelyezett hajók száma
    int placed_boats[4];


    init(table, placed_boats);
    submit(table,placed_boats,true,'A',0,3);
    submit(table,placed_boats,true,'A',2,3);
    submit(table,placed_boats,false,'D',6,2);
    submit(table,placed_boats,false,'J',2,4);
    submit(table,placed_boats,true,'F',8,5);
    printTable(table);
    
    return 0;
}


// nem muszáj, hogy a placed_boats-hoz felvegyük
// a méretet, mivel tudjuk fixen hogy 4
void init(int table[][HEIGHT], int placed_boats[]){
    int i;
    for(i = 0; i < WIDTH; i++){
        int j;
        for(j = 0; j < HEIGHT; j++){
            table[i][j] = 0;
        }
    }
    for(i = 0; i < 4; i++){
        placed_boats[i] = 0;
    }
}


void printTable(int table[][HEIGHT]){
    int i;
    for(i = 0; i < WIDTH; i++){
        int j;
        for(j = 0; j < HEIGHT; j++){
            printf("%i ", table[i][j]);
        }
        printf("\n");
    }
}


// direction true, ha vízszintes, false ha függőleges.
// 3 feltétel:
// megfelelő méret -> lelógás -> érintkezés
void submit(int table[][HEIGHT], int placed_boats[], bool direction, char x_char, int y, int length){
    // y-t intté varázsoljuk:
    int x = x_char - 65; // A az 65 intben

    // lelógás checkhez meg érintkezéshez jó lenne,
    // ha tudnánk az összes x-y párját a hajónak:
    // maximum 5 hosszú a hajó, és hogy ne
    // változóval deklaráljuk, maxot feltételezünk
    // de csak length-ig fogjuk nézni.
    int x_cords[5];
    int y_cords[5];
    x_cords[0] = x;
    y_cords[0] = y;
    if(direction){
        int i;
        for(i = 1; i < length; i++){
            x_cords[i] = x;
            y_cords[i] = y_cords[i - 1] + 1;
        }
    }else{
        int i;
        for(i = 1; i < length; i++){
            x_cords[i] = x_cords[i - 1] + 1;
            y_cords[i] = y;
        }
    }
    int i;
    for(i = 0; i < length; i++){
        printf("x = %i, y = %i\n", x_cords[i], y_cords[i]);
    }

    if(meret_check(placed_boats, length)){
        if(!lelogas_check(x_cords, y_cords, length)){
            if(!erintkezes_check(x_cords, y_cords, length, table)){
                elhelyezes(table, x_cords, y_cords, length);
                placed_boats[length - 2]++;
                printf("Oke\n");
            }else{
                printf("Erintkezik mas hajoval!\n");
            }
        }else{
            printf("Lelog a hajo!\n");
        }
    }else{
        printf("Invalid meretu hajo!\n");
    }
}


bool meret_check(int placed_boats[], int length){
    if(!(1 < length && length < 6)){
        return false;
    }else if(length == 3 && placed_boats[1] == 2){
        return false;
    }else if(length != 3 && placed_boats[length - 2] == 1){
        return false;
    }
    return true;
}


bool lelogas_check(int x_cords[], int y_cords[], int length){
    int i;
    for(i = 0; i < length; i++){
        if(0 <= x_cords[i] && x_cords[i] < WIDTH){
            if(0 <= y_cords[i] && y_cords[i] < HEIGHT){
                // ez az x-y pár jó.
            }else{
                return true;
            }
        }else{
            return true;
        }
    }
    return false;
}


bool erintkezes_check(int x_cords[], int y_cords[], int length, int table[][HEIGHT]){
    int i;
    // 3x3-mas négyzetet kell ellenőriznünk minden x-y párnál (középen van az elem)
    for(i = 0; i < length; i++){
        int x = x_cords[i];
        int y = y_cords[i];
        int j;
        for(j = x - 1; j <= x + 1; j++){
            int k;
            for(k = y - 1; k <= y + 1; k++){
                if(0 <= j && j < WIDTH && 0 <= k && k < HEIGHT){
                    if(table[j][k] != 0){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void elhelyezes(int table[][HEIGHT], int x_cords[], int y_cords[], int length){
    int i;
    for(i = 0; i < length; i++){
        table[x_cords[i]][y_cords[i]] = 1;
    }
}