#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[69], **pstr;
    int tam;

    pstr = (char **) malloc(sizeof(char *) * 5);

    for(int i = 0; i < 5; i++)
    {
        scanf("%[^\n]%*c", str);
        pstr[i] = (char) malloc (sizeof(char) * strlen(str));
        for(int j = 0; j < strlen(str); j++) {
            pstr[i][j] = str[j];
        }
        pstr[i][strlen(str)] = '\0';
    }


    return 0;
}