#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char vet[200];
    char * str1;
    int tam;

    scanf("%[^\n]%*c", vet);
    tam = strlen(vet);
    str1 = (char *)malloc(sizeof(char) * tam);

    for(int i = 0; i < tam; i++){
        str1[i] = vet[tam - 1 - i];        
    }
    str1[tam] = '\0';

    for(int i = 0; i < tam; i++){
        printf("%c", vet[i]);
    }

    printf("\n");

    for(int i = 0; i < tam; i++){
        printf("%c", str1[i]);
    }
    return 0;
}