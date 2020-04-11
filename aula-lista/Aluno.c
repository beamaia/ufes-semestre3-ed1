#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat;
    char* nome;
    float CR;
};

Aluno inicializaAluno (int mat, char*  nome, float CR) {
    Aluno al = (Aluno) malloc(sizeof(struct aluno));

    al->mat = mat;
    al->nome = strdup(nome);
    al->CR = CR;

    return al;
}

void imprimeAluno (Aluno al) {
    printf("Matricula: %d, Nome: %s, CR: %0.2f\n", al->mat, al->nome, al->CR);
}

int getMatricula (Aluno al) {
    return al->mat;
}

char* getNome (Aluno al) {
    return al->nome;
}

float getCR (Aluno al) {
    return al->CR;
}

void destroiAluno (Aluno al) {
    free(al->nome);
    free(al);
}