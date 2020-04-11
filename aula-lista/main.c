#include <stdio.h>
#include "ListaComSentinela.h"

//Teste da video (retira elemento do meio)
//int main() {
//    Aluno patricia = inicializaAluno(123, "Patricia", 10); //ultimo aluno da lista
//    Aluno alice = inicializaAluno(656, "Alice", 5);
//    Aluno maria = inicializaAluno(21, "Maria", 9);
//    Aluno joao = inicializaAluno(999, "Joao", 8); //primeiro aluno da lista
//
//    Lista* lista = inicializaLista();
//    insereLista(lista, patricia);
//    insereLista(lista, alice);
//    insereLista(lista, maria);
//    insereLista(lista, joao);
//
//    printf("Imprimindo a lista:\n");
//    imprimeLista(lista);
//
//    retiraLista(lista, "Alice");
//    printf("Imprimindo a lista\n");
//    imprimeLista(lista);
//
//    insereLista(lista, alice);
//    printf("Imprimindo a lista\n");
//    imprimeLista(lista);
//
//    destroiLista(lista);
//    return 0;
//}

//Retirando o ultimo elemento
//int main() {
//    Aluno patricia = inicializaAluno(123, "Patricia", 10);
//    Aluno alice = inicializaAluno(656, "Alice", 5);
//    Aluno maria = inicializaAluno(21, "Maria", 9);
//
//    Lista* lista = inicializaLista();
//    insereLista(lista, patricia);
//    insereLista(lista, alice);
//    insereLista(lista, maria);
//
//    printf("Imprimindo a lista:\n");
//    imprimeLista(lista);
//
//    retiraLista(lista, "Patricia");
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    insereLista(lista, patricia);
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    destroiLista(lista);
//    return 0;
//}


//Retirando o primeiro elemento
int main() {
    Aluno patricia = inicializaAluno(123, "Patricia", 10);
    Aluno alice = inicializaAluno(656, "Alice", 5);
    Aluno maria = inicializaAluno(21, "Maria", 9);
    Aluno retirado;

    Lista* lista = inicializaLista();
    insereLista(lista, patricia);
    insereLista(lista, alice);
    insereLista(lista, maria);

    printf("Imprimindo a lista:\n");
    imprimeLista(lista);

    retirado = retiraLista(lista, "Maria");
    printf("\nAluno retirado:\n");
    imprimeAluno(retirado);

    printf("\nImprimindo a lista\nlu");
    imprimeLista(lista);

    insereLista(lista, maria);
    printf("\nImprimindo a lista\n");
    imprimeLista(lista);

    destroiLista(lista);
    return 0;
}

//Lista com um elemento
//int main() {
//    Aluno patricia = inicializaAluno(123, "Patricia", 10);
//    Lista* lista = inicializaLista();
//    insereLista(lista, patricia);
//
//    printf("Imprimindo a lista:\n");
//    imprimeLista(lista);
//
//    retiraLista(lista, "Patricia");
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    insereLista(lista, patricia);
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    destroiLista(lista);
//    return 0;
//}

//Lista vazia
//int main() {
//    Aluno patricia = inicializaAluno(123, "Patricia", 10);
//    Lista* lista = inicializaLista();
//
//    printf("Imprimindo a lista:\n");
//    imprimeLista(lista);
//
//    retiraLista(lista, "Patricia");
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    insereLista(lista, patricia);
//    printf("\nImprimindo a lista\n");
//    imprimeLista(lista);
//
//    destroiLista(lista);
//    return 0;
//}
