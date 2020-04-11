#ifndef _aluno_h
#define _aluno_h

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct aluno* Aluno;

    Aluno inicializaAluno (int mat, char*  nome, float CR);
    void imprimeAluno (Aluno al);
    int getMatricula (Aluno al);
    char* getNome (Aluno al);
    float getCR (Aluno al);
    void destroiAluno (Aluno al);
#endif //_aluno_h
