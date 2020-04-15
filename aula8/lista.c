#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct tipoitem {
    char *nome,
         *endereco;
    int matricula;
};

typedef struct celula Celula;
struct celula {
    TipoItem* aluno;
    Celula* proximo;
};

struct tipolista {
    Celula* prim,
          * ult;

};

TipoLista* InicializaLista() {
    TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));
    lista->prim = lista->ult = NULL;

    return lista;
}

void Insere (TipoItem* aluno, TipoLista* lista) {
    Celula* novaCelula = (Celula*) malloc (sizeof(Celula));
    novaCelula->aluno = aluno;

    novaCelula->proximo = lista->prim;
    lista->prim = novaCelula;
    
    if (lista->ult == NULL) {
        lista->ult = novaCelula;
    }
}

int getMatricula(TipoItem* aluno) {
    return aluno->matricula;
}

TipoItem* Retira (TipoLista* lista, int mat) {
    TipoItem* aluno;
    Celula* aux = lista->prim, *anterio = NULL;

    while(aux != NULL && (getMatricula(aux->aluno) != mat)) {
        anterio = aux;
        aux = aux->proximo;
    }

    if (aux == NULL) {
        return NULL;
    }

    aluno = aux->aluno;
    if (aux == lista->prim && aux == lista->ult) {  
        lista->prim = lista->ult = NULL;
    } else if (aux == lista->prim) { 
        lista->prim = aux->proximo;
    } else if (aux == lista->ult) { 
        lista->ult = anterio;
        lista->ult->proximo = NULL;
    } else { 
        anterio->proximo = aux->proximo;
    }

    free(aux);
    return aluno;
}

void imprimeAluno(TipoItem* aluno) {
    printf("Aluno: %s, Matricula: %d, Endereço: %s\n", aluno->nome, aluno->matricula, aluno->endereco);
}
/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoLista* lista) {
    Celula* aux;
    
    for(aux = lista->prim; aux != NULL; aux=aux->proximo) {
        imprimeAluno(aux->aluno);
    }
}

void liberaAluno (TipoItem* aluno) {
    free(aluno->endereco);
    free(aluno->nome);
    free(aluno);
}

TipoLista* Libera (TipoLista* lista) {
    Celula* aux1 = lista->prim, * aux2;

    while (aux1 != NULL)
    {
        aux2 = aux1->proximo;
        liberaAluno(aux1->aluno);
        free(aux1);
        aux1 = aux2;
    }

    free(lista);    
}


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco) {
    TipoItem* aluno = (TipoItem*) malloc(sizeof(TipoItem));
    aluno->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    aluno->endereco = (char*) malloc(sizeof(char) * (strlen(endereco) + 1));

    strcpy(aluno->nome, nome);
    strcpy(aluno->endereco, endereco);

    aluno->matricula = matricula;
    return aluno;
}