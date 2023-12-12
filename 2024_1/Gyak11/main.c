#include<stdio.h>
#include<stdlib.h> // malloc, realloc, free
#include<string.h>

char* reverse(char* string);

int main(){
    int szamok[10];
    // malloc(méret (byte))
    // visszaad egy pointert aminek lefoglal byte-nyi adatot
    int *szamok2 = malloc(sizeof(int) * 10);
    *szamok2 = 10;
    *(szamok2 + 5) = 30;
    szamok2[3] = 15;
    
    int *ujtomb = realloc(szamok2, sizeof(int) * 6);
    free(ujtomb);

    char text[21];
    scanf("%s", text);
    printf("%d\n", strlen(text));
    char *text2 = malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(text2, text);
    printf("%s\n", text2);
    // free(text2);

    char *result = reverse(text2);
    printf("%s\n", result);
    free(result);
    free(text);

    char **stringTomb = malloc(sizeof(char*) * 5);
    // char *stringTomb[5];
    // stringTomb[0] = malloc(hossz * sizeof(char)); 

    // miután végeztünk
    int i;
    for (i = 0; i < 5; i++){
        free(stringTomb[i]);
    }
    free(stringTomb);
    return 0;
}

char* reverse(char* string){
    int len = strlen(string);
    char *result = malloc((len + 1) * sizeof(char));
    int i;
    // for(i = 0; i < len / 2; i++){
    //     char temp = string[i];
    //     string[i] = string[(len - i - 1)];
    //     string[(len - i - 1)] = temp;
    // }
    for(i = 0; i < len; i++){
        result[i] = string[(len - i - 1)];
    }
    // printf("%s\n", result);
    result[len] = '\0';
    // printf("%s\n", result);
    return result;
}