#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "pedido.h"

typedef struct cel Celula;
struct cel {
    TProduto *prod;
    Celula *prox;
};

struct pedido {
    char *dono;
    Celula *prim, 
           *ult;
};

TPedido* InicPedido (char* dono) {
    TPedido * pedido = (TPedido *) malloc (sizeof(TPedido));
    pedido->dono = (char *) malloc (sizeof(char) * (strlen(dono) + 1));
    strcpy(pedido->dono, dono);
    pedido->prim = NULL;
    pedido->ult = NULL;

    return pedido;
}

void IncluiProdutoPedido (TPedido* pedido, TProduto* prod) {
    Celula *novoPedido = (Celula*) malloc(sizeof(Celula));
    novoPedido->prod = prod;
    novoPedido->prox = NULL;

    if (pedido->prim == NULL) {
        pedido->prim = novoPedido;
        pedido->ult = novoPedido;
    } else {
        pedido->ult->prox = novoPedido;
        pedido->ult = novoPedido;
    }


}

void ImprimePedido (TPedido* pedido) {
    printf("Dono: %s\n", pedido->dono);
    if(pedido->prim == NULL) {
        printf("Nao ha produtos neste pedido!\n");
    } else {
        for(Celula *aux = pedido->prim; aux != NULL; aux = aux->prox) {
            ImprimeIngredientes(aux->prod);
        }
    }
}

void RetiraProdutoPedido (TPedido* pedido, char* prod) {
    Celula *aux = pedido->prim, *anterior;

    while (aux != NULL && (strcmp(prod, RetornaNome(aux->prod)) != 0)){
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL){
        return;
    }

    if (aux == pedido->prim && aux == pedido->ult) { //Unico elemento
        pedido->prim = NULL;
        pedido->ult = NULL;
    } else if (aux == pedido->prim){ //Primeiro elemento
        pedido->prim = aux->prox;
    } else if (aux == pedido->ult) { //Ultimo elemento
        anterior->prox = NULL;
        pedido->ult = anterior;
    } else { //No meio da lista de produtos
        anterior->prox = aux->prox;
    }

    free(aux);
}

/*----------------------------------------------------------------------
 * Funcao auxiliar para liberar as celulas do pedido.
 *----------------------------------------------------------------------*/
void liberaPedido (TPedido* pedido){
    Celula *aux1 = pedido->prim,
           *aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }

    free(pedido->dono);
    free(pedido);
}

int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    if (pedido == NULL) {
        return 1;
    }

    Celula *aux;
    int somaCalorias = 0;
    for(aux = pedido->prim; aux != NULL; aux=aux->prox) {
        somaCalorias += Calorias(aux->prod);
    }

    if (somaCalorias > restricao_calorica) {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    int ingredientePresente = 0;
    for(aux = pedido->prim; aux != NULL; aux = aux->prox) {
        if(VerificaIngrediente(aux->prod, restricao_alimentar)) {
            printf("nPedido não Enviado! Restricao alimentar no produto: %s", RetornaNome(aux->prod));
            return 0;
        }
    }

    liberaPedido(pedido);
    return 1;
}
