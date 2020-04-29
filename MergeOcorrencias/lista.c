#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno {
    char *nome;
    int matricula;
};

typedef struct celula TCelula;
struct celula {
    TAluno *aluno;
    TCelula *prox;
};

struct lista{
    TCelula *prim,
            *ult;
};

TLista* CriaLista() {
    TLista *lista = (TLista *) malloc(sizeof(TLista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

TAluno* InicializaAluno(char* nome, int matricula) {
    TAluno *aluno = (TAluno *) malloc(sizeof(TAluno));
    
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;

    return aluno;
}

void InsereAluno (TLista* lista, TAluno* aluno) {
    TCelula *novoAluno = (TCelula *) malloc(sizeof(TCelula));
    novoAluno->aluno = aluno;
    novoAluno->prox = lista->prim;

    lista->prim = novoAluno; 

    if (lista->ult == NULL) {
        lista->ult = novoAluno;
    }
}

/************************
 * Funcao auxiliar para acessar o valor da. matricula do aluno
 ************************/
int RetornaMatricula(TAluno *aluno) {
    return aluno->matricula;
}

TAluno* Retira (TLista* lista, int mat) {
    TAluno *alunoRetirado;
    TCelula *anterior = NULL, *aux = lista->prim;

    while(aux != NULL && (RetornaMatricula(aux->aluno) != mat)) {
        anterior = aux;
        aux = aux->prox;
    } 

    if(aux == NULL) {
        return NULL;
    }

    alunoRetirado = aux->aluno;
    if (lista->prim == aux && lista->ult == aux) {
        lista->prim = NULL;
        lista->ult = NULL;
    } else if (aux == lista->prim) {
        lista->prim = aux->prox;
    } else if (aux == lista->ult) {
        lista->ult = anterior;
        anterior->prox = NULL;
    } else {
        anterior->prox = aux->prox;
    }
    
    free(aux);
    
    return alunoRetirado;
}


/************************
 * Funcao auxiliar para verificar se as matriculas sao iguais.
 ************************/
int MatriculasIguais (TAluno *aluno1, TAluno *aluno2) {
    if(RetornaMatricula(aluno1) == RetornaMatricula(aluno2)) 
        return 1;
    return 0;
}

void RetiraRepetidos (TLista* lista) {
    if (lista->prim == NULL) {
        return;
    }
    
    TCelula *celObservada,
            *segCelObservada,
            *aux;
    TAluno *aluno;

    celObservada = lista->prim;

    while(celObservada != NULL) {
        segCelObservada = celObservada->prox;

        aux = celObservada->prox;
        while(aux != NULL) {
            
            if(MatriculasIguais(aux->aluno, celObservada->aluno)) {
                aluno = Retira(lista, RetornaMatricula(aux->aluno));
                break;
            }

            aux = aux->prox;
        }
        
        celObservada = segCelObservada;
    }
}

//Funcao com erro
// void RetiraRepetidos (TLista* lista) {
//     if (lista->prim == NULL) {
//         return;
//     }
    
//     TCelula *celObservada,
//             *aux,
//             *aux2;
//     TAluno *aluno;

//     for(celObservada = lista->prim; celObservada != NULL; celObservada = celObservada->prox) {
//         printf("%d\n", celObservada->aluno->matricula);
//         aux = celObservada->prox;
//         while(aux != NULL) {
//             aux2 = aux->prox;
//             if(MatriculasIguais(aux->aluno, celObservada->aluno)) {
//                 aluno = Retira(lista, RetornaMatricula(aux->aluno));
//                 aux = aux2;
//                 break;
//             }

//             aux = aux2;
//         }
//     }
// }

void InsereAlunoMerge(TLista* lista, TAluno *aluno) {
    TCelula *novoAluno = (TCelula *) malloc(sizeof(TCelula));
   
    novoAluno->aluno = aluno;
    novoAluno->prox = lista->prim;

    lista->prim = novoAluno; 

    if(lista->ult == NULL) {
        lista->ult = lista->prim;
    }

}

TLista* Merge (TLista* turma1, TLista* turma2) {
    TLista *novaLista = CriaLista();

    //Caso em que as duas turmas estao vazias
    if (turma1->prim == NULL && turma2->prim == NULL) {
        return novaLista;
    //Caso em que a primeira turma esta vazia
    } else if (turma1->prim == NULL) {
        novaLista->prim = turma2->prim;
        novaLista->ult = turma2->ult;
        turma2->prim = NULL;
        turma2->ult = NULL;
        return novaLista;
    //Caso em que a segunda turma esta vazia
    } else if (turma2->prim == NULL) {
        novaLista->prim = turma1->prim;
        novaLista->ult = turma1->ult;
        turma1->prim = NULL;
        turma1->ult = NULL;
        return novaLista;
    }

    //Caso em que as turmas nao estao vazias
    TCelula *auxTurma1, *auxTurma2, *aux;

    //Auxiliares que conterao as duas turmas
    auxTurma1 = turma1->prim;
    auxTurma2 = turma2->prim;

    while (auxTurma1 != NULL || auxTurma2 != NULL) {
        if (auxTurma1 != NULL) {
            InsereAlunoMerge(novaLista, auxTurma1->aluno);
            aux = auxTurma1->prox;
            free(auxTurma1);
            auxTurma1 = aux;
        }

        if (auxTurma2 != NULL) {
            InsereAlunoMerge(novaLista, auxTurma2->aluno);
            aux = auxTurma2->prox;
            free(auxTurma2);
            auxTurma2 = aux;
        }
    }

    turma1->prim = NULL;
    turma1->ult = NULL;
    turma2->prim = NULL;
    turma2->ult = NULL;
    return novaLista;
}

void LiberaAluno (TAluno* aluno) {
    free(aluno->nome);
    free(aluno);
}

/************************
 * Funcao auxiliar para apresentar alunos.
 ************************/
void ImprimeAluno(TAluno *aluno) {
    printf("Nome: %s Matricula: %d\n", aluno->nome, aluno->matricula);
}

void Imprime (TLista* lista) {
    TCelula *aux;

    for(aux = lista->prim; aux != NULL; aux = aux->prox) {
        ImprimeAluno(aux->aluno);
    }

}

void LiberaLista (TLista* lista) {
    TCelula *aux1 = lista->prim, *aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        LiberaAluno(aux1->aluno);
        free(aux1);
        aux1 = aux2;
    }

    free(lista);    
}