#include <stdio.h>
#include <stdlib.h>

#include "../include/funcoes-alocacao.h"

int verificaAlocacaoLivros(Livro **lv, int n, int *n_aloc)
{
    if (n == *n_aloc)
    {
        (*n_aloc) *= 2;
        realloc(*lv, (*n_aloc) * sizeof(Livro));
    }

    if (*lv == NULL)
    {
        printf("Erro ao realocar memória para livros.");
        return (1);
    }

    return 0;
}

int verificaAlocacaoUsuarios(Usuario **us, int n, int *n_aloc)
{
    if (n == *n_aloc)
    {
        (*n_aloc) *= 2;
        realloc(*us, (*n_aloc) * sizeof(Usuario));
    }

    if (*us == NULL)
    {
        printf("Erro ao realocar memória para usuários.");
        return (1);
    }

    return 0;
}

int verificaAlocacaoEmprestimos(Emprestimo **emp, int n, int *n_aloc)
{
    if (n == *n_aloc)
    {
        (*n_aloc) *= 2;
        realloc(*emp, (*n_aloc) * sizeof(Emprestimo));
    }

    if (*emp == NULL)
    {
        printf("Erro ao realocar memória para empréstimos.\n");
        return (1);
    }

    return 0;
}

int inicializaEstruturaLivros(Livro **lv)
{
    *lv = malloc(ALOC_INICIAL * sizeof(Livro));

    if (*lv == NULL)
    {
        printf("Erro ao alocar memória para Livros.\n");

        return 1;
    }

    return 0;
}

int inicializaEstruturaUsuarios(Usuario **us)
{
    *us = malloc(ALOC_INICIAL * sizeof(Usuario));
    if (*us == NULL)
    {
        printf("Erro ao alocar memória para Usuários!\n");
        return 1;
    }

    return 0;
}

int inicializaEstruturaEmprestioms(Emprestimo **emp)
{
    *emp = malloc(ALOC_INICIAL * sizeof(Emprestimo));
    if (*emp == NULL)
    {
        printf("Erro ao alocar memória para Empréstimos!\n");
        return 1;
    }

    return 0;
}