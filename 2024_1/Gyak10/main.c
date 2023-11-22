#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    printf("%i\n", argc);
    printf("%s\n", argv[1]);
    if(argc == 3){
        //jo
        // ha vizsgálni kéne hogy az argumentum szám-e
        // akkor for ciklus és isdigit() a ctype.h-ból
        int szam = atoi(argv[2]);
        printf("Szam = %i\n", szam);
    }else if(argc > 3){
        // tul sok paraméter
        return -1;
    }else{
        //tul keves parameter
        return -1;
    }

    // Másféle beolvasás
    char buffer[100];
    fgets(buffer, 100, stdin);
    printf("%s\n", buffer);
    int i;
    for(i = 0; i < 100; i++){
        // fgetsnél '\n'
        printf("Mostani = %c\n", *(buffer + i));
        if(*(buffer + i) == '\0'){
            break;
        }

        //rakjunk '\0' a végére
        // if(buffer[i] == '\n' && i != 99){
        //     buffer[i+1] = '\0';
        // }
    }
    // strcmp(string1, string2)
    // ha az eredmény 0, akkor ugyanaz a string
    // ha az eredmény >0 akkor a második string hamarabb jön az abc-ben
    // ja az eredmény <0 akkor az első string hamarabb jön az abc-ben

    printf("%i\n", strcmp("alma","barack"));
    // strcpy(honnan, hova) méreteket hogy nézi, \0

    FILE* fp;
    fp = fopen("input.txt", "r");
    char stringem[100];
    fgets(stringem, 100, fp);
    fgets(stringem, 100, fp);
    fgets(stringem, 100, fp);
    // while(!feof(fp))
    fclose(fp);
    printf("Stringem = %s\n", stringem);

    FILE* fp2;
    fp2 = fopen("output.txt", "w");
    fprintf(fp2, "Megadhatunk barmit %i", 20);
    fclose(fp2);
    return 0;
}
