#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int ** mat;
    int linhas, colunas;
};

void erroInicializacao() {
    printf("Erro ao alocar memória\n");
    exit(1);
}

Matriz* inicializaMatriz(int nlinhas, int ncolunas) {
    Matriz *m = (Matriz *) malloc(sizeof(Matriz));
    if(!m)
        erroInicializacao();

    m->linhas = nlinhas;
    m->colunas = ncolunas;
    m->mat = (int **) malloc(sizeof(int*) * m->linhas);
    if(!m->mat) 
        erroInicializacao();

    for(int i = 0; i < m->linhas; i++){
        m->mat[i] = (int *) malloc(sizeof(int) * m->colunas);
        if(!m->mat[i])
            erroInicializacao();
    }

    return m;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem) {
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    return mat->mat[linha][coluna];
}

int recuperaNColuna(Matriz* mat) {
    return mat->colunas;
}

int recuperaNLinhas(Matriz* mat) {
    return mat->linhas;
}

Matriz* transposta(Matriz *mat) {
    Matriz *matTrans;
    matTrans = inicializaMatriz(mat->colunas, mat->linhas);

    for(int i = 0; i < matTrans->linhas; i++) {
        for(int j = 0; j < matTrans->colunas; j++) {
            modificaElemento(matTrans, i, j, mat->mat[j][i]);
        }
    }

    return matTrans;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2) {
    if(mat1->colunas != mat2->linhas) {
        printf("Não podemos multiplicar as matrizes\n");
        exit(1);
    }
    
    Matriz* matMul = inicializaMatriz(mat1->linhas, mat2->colunas);
    int elem = 0;
    for(int i = 0; i < matMul->linhas; i++) {
        for(int j = 0; j < matMul->colunas; j++) {
            for(int k = 0; k < mat1->colunas; k++) {
                elem += mat1->mat[i][k] * mat2->mat[k][j];
            }
            matMul->mat[i][j] = elem;
            elem = 0;
        }
    }
    
    return matMul;
}

void imprimeMatriz(Matriz* mat) {
    for(int i = 0; i < mat->linhas; i++) {
        for(int j = 0; j < mat->colunas; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat) {
    for(int i = 0; i < mat->linhas; i++) {
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}