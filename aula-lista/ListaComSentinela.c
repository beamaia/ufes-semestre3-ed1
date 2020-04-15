#include "ListaComSentinela.h"
#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel Celula;
struct cel{
    Aluno al;
    Celula* prox;
};

struct lista {
    Celula* prim;
    Celula* ult;
};

Lista * inicializaLista() {
   Lista* lista = (Lista*) malloc(sizeof(Lista));
   lista->prim = NULL;
   lista->ult = NULL;

   return lista;
}

//No inicio
void insereListaInicio(Lista* lista, Aluno al) {
    Celula* novaCelula = (Celula*) malloc(sizeof(Celula));
    novaCelula->al = al;

    novaCelula->prox = lista->prim;

    lista->prim = novaCelula;

    if(lista->ult == NULL) {
        lista->ult = novaCelula;
    }
}

//No final
void insereListaFinal(Lista* lista, Aluno al) {
    Celula* novaCelula = (Celula*) malloc(sizeof(Celula));
    novaCelula->al = al;
    novaCelula->prox = NULL;
    
    if (lista->prim == NULL) {
        lista->prim = novaCelula;
        lista->ult = lista->prim;
    } else {
        lista->ult->prox = novaCelula;
        lista->ult = novaCelula;
    }
}

void imprimeLista(Lista* lista) {
    Celula* p;

    printf("---------------------------------------\n");
    for(p = lista->prim; p != NULL; p = p->prox) {
        imprimeAluno(p->al);
    }
    printf("---------------------------------------\n");

}

Aluno retiraLista(Lista* lista, char* chave) {
    Celula* p = lista->prim;
    Aluno al;
    Celula* ant = NULL;

    while (p!= NULL && strcmp(getNome(p->al), chave)) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return NULL;
    }

    al = p->al;

    if (p == lista->prim && p == lista->ult) {  // unico elemento da lista
        lista->prim = lista->ult = NULL;
    } else if (p == lista->prim) { // se for o primeiro elemento da lista
        lista->prim = p->prox;
    } else if (p == lista->ult) { // se for o ultimo elemento da lista
        lista->ult = ant;
        lista->ult->prox = NULL;
    } else { //se tiver no meio da lista
        ant->prox = p->prox;
    }

    free(p); //libera apenas a celula

    return al; //retornar o aluno
}

void destroiLista(Lista* lista) {
    Celula* p = lista->prim;
    Celula* t;

    while(p != NULL) {
        t = p->prox;
        destroiAluno(p->al);
        free(p);
        p = t;
    }

    free(lista);
}