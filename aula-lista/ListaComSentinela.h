#ifndef _lista_com_sentinela_h
#define _lista_com_sentinela_h
    #include "Aluno.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct lista Lista;
    Lista * inicializaLista();
    void insereLista(Lista* lista, Aluno al);
    void imprimeLista(Lista* lista);
    Aluno retiraLista(Lista* lista, char* chave);
    void destroiLista(Lista* lista);

#endif //_lista_com_sentinela_h
