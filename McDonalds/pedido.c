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
/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */
struct pedido {
    char *dono;
    Celula *prim, 
           *ult;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono) {
    TPedido * pedido = (TPedido *) malloc (sizeof(TPedido));
    pedido->dono = (char *) malloc (sizeof(char) * (strlen(dono) + 1));
    strcpy(pedido->dono, dono);
    pedido->prim = NULL;
    pedido->ult = NULL;

    return pedido;
}


/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod) {
    if (pedido == NULL) {
        return;
    } 

    TProduto *produto;
    Celula *aux = pedido->prim, *anterior;

    while (aux != NULL && (strcmp(prod, RetornaNome(aux->prod)))){
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL){
        return;
    }

    produto = aux->prod;
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

    // free(aux);
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
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

    free(aux);
    free(pedido->dono);
    free(pedido);
    return 1;
}
