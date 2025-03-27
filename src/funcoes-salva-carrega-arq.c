#include <stdio.h>
#include <stdlib.h>

#include "../include/funcoes-salva-carrega-arq.h"

int salvarLivros(Livro *lv, int n)
{
    FILE *fp = fopen(arqLivro, "wb");
    if (fp == NULL)
    {
        printf("Erro ao criar o arquivo de livros.\n");

        return 1;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao salvar o número de livros.\n");

        fclose(fp);
        return 1;
    }

    if (n > 0)
    {
        if (fwrite(lv, sizeof(Livro), n, fp) != n)
        {
            printf("Erro ao salvar os dados dos livros.\n");

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int carregarLivros(Livro **lv, int *n, int *n_aloc)
{
    FILE *fp = fopen(arqLivro, "rb");
    if (fp == NULL)
    {
        printf("Erro ao ler o arquivo de livros.\n");

        return 1;
    }

    if (fread(n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao ler o número de livros.\n");
        fclose(fp);

        return 1;
    }

    if (*n == 0)
    {
        *lv == NULL;
        fclose(fp);

        return 0;
    }

    *n_aloc = (*n) * 2;
    *lv = malloc((*n_aloc) * sizeof(Livro));
    if (*lv == NULL)
    {
        printf("Erro ao alocar memória para livros.\n");
        fclose(fp);

        return 1;
    }

    if (fread(*lv, sizeof(Livro), *n, fp) != *n)
    {
        printf("Erro ao ler os dados dos livros.\n");
        free(*lv);
        fclose(fp);

        return 1;
    }

    fclose(fp);
    return 0;
}

int salvarUsuarios(Usuario *us, int n)
{
    FILE *fp = fopen(arqUsuario, "wb");
    if (fp == NULL)
    {
        printf("Erro ao criar o arquivo de usuários.\n");

        return 1;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao salvar o número de usuários.\n");

        fclose(fp);
        return 1;
    }

    if (n > 0)
    {
        if (fwrite(us, sizeof(Usuario), n, fp) != n)
        {
            printf("Erro ao salvar os dados dos usuários.\n");

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int carregarUsuarios(Usuario **us, int *n, int *n_aloc)
{
    FILE *fp = fopen(arqUsuario, "rb");
    if (fp == NULL)
    {
        printf("Erro ao ler o arquivo de usuários.\n");

        return 1;
    }

    if (fread(n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao ler o número de usuários.\n");
        fclose(fp);

        return 1;
    }

    if (*n == 0)
    {
        *us == NULL;
        fclose(fp);

        return 0;
    }

    *n_aloc = (*n) * 2;
    *us = malloc((*n_aloc) * sizeof(Usuario));
    if (*us == NULL)
    {
        printf("Erro ao alocar memória para usuários.\n");
        fclose(fp);

        return 1;
    }

    if (fread(*us, sizeof(Usuario), *n, fp) != *n)
    {
        printf("Erro ao ler os dados dos usuários.\n");
        free(*us);
        fclose(fp);

        return 1;
    }

    fclose(fp);
    return 0;
}

int salvarEmprestimos(Emprestimo *emp, int n)
{
    FILE *fp = fopen(arqEmprestimo, "wb");
    if (fp == NULL)
    {
        printf("Erro ao criar o arquivo de empréstimos.\n");

        return 1;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao salvar o número de empréstimos.\n");

        fclose(fp);
        return 1;
    }

    if (n > 0)
    {
        if (fwrite(emp, sizeof(Emprestimo), n, fp) != n)
        {
            printf("Erro ao salvar os dados dos empréstimos.\n");

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int carregarEmprestimos(Emprestimo **emp, int *n, int *n_aloc)
{
    FILE *fp = fopen(arqEmprestimo, "rb");
    if (fp == NULL)
    {
        printf("Erro ao ler o arquivo de empréstimos.\n");

        return 1;
    }

    if (fread(n, sizeof(int), 1, fp) != 1)
    {
        printf("Erro ao ler o número de empréstimos.\n");
        fclose(fp);

        return 1;
    }

    if(*n == 0)
    {
        *emp = NULL;
        fclose(fp);

        return 0;
    }

    *n_aloc = (*n) * 2;
    *emp = malloc((*n_aloc) * sizeof(Emprestimo));
    if (*emp == NULL)
    {
        printf("Erro ao alocar memória para empréstimos.\n");
        fclose(fp);

        return 1;
    }

    if (fread(*emp, sizeof(Emprestimo), *n, fp) != *n)
    {
        printf("Erro ao ler os dados dos empréstimos.\n");
        free(*emp);
        fclose(fp);

        return 1;
    }

    fclose(fp);

    return 0;
}