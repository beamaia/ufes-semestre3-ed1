#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[] = {23, 45, 12, 34, 21, 76, 8, 1234, 32, 10};
    void **vet2 = malloc(10 * sizeof * vet2);
    int *vet3 = (int *) malloc(sizeof(int) * 10);

    for(int i = 0; i < 10; i++) {
        vet2[i] = &vet[i];
        
    }

    void *temp1;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9 - i; j++) {
            if(vet2[j] > vet2[j + 1]) {
                temp1 = vet2[j];
                vet2[j] = vet2[j + 1];
                vet2[j + 1] = temp1;
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("%d: %p\n", i, vet2[i]);
    }

    for(int i = 0; i < 10; i++) {
        free(vet2[i]); 
    }
    
    return 0;

}