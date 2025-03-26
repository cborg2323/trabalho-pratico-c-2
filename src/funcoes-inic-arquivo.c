#include <stdio.h>

#include "../include/funcoes-inic-arquivo.h"

int arquivosInicializados()
{
    int flag_nao_inicializados = 0;

    FILE *fpLivro = fopen(arqLivro, "r");
    FILE *fpUsuario = fopen(arqUsuario, "r");
    FILE *fpEmprestimo = fopen(arqEmprestimo, "r");
    if (fpLivro == NULL || fpUsuario == NULL || fpEmprestimo == NULL)
    {
        flag_nao_inicializados = 1;
        return 0;
    }

    if (fpLivro != NULL)
    {
        fclose(fpLivro);
    }
    if (fpUsuario != NULL)
    {
        fclose(fpUsuario);
    }
    if (fpEmprestimo != NULL)
    {
        fclose(fpEmprestimo);
    }

    if (flag_nao_inicializados)
    {
        return 0;
    }

    return 1;
}

int arquivoLivrosVazio()
{
    int numeroLivros;
    FILE *fpLivro = fopen(arqLivro, "r");
    if (fpLivro == NULL)
    {
        return 1;
    }

    fread(&numeroLivros, sizeof(int), 1, fpLivro);
    fclose(fpLivro);

    if (numeroLivros == 0)
    {
        return 1;
    }
    return 0;
}

int arquivoUsuariosVazio()
{
    int numeroUsuarios;
    FILE *fpUsuario = fopen(arqUsuario, "r");
    if (fpUsuario == NULL)
    {
        return 1;
    }

    fread(&numeroUsuarios, sizeof(int), 1, fpUsuario);
    fclose(fpUsuario);

    if (numeroUsuarios == 0)
    {
        return 1;
    }
    return 0;
}

int arquivoEmprestimosVazio()
{
    int numeroEmprestimos;
    FILE *fpEmprestimo = fopen(arqEmprestimo, "r");
    if (fpEmprestimo == NULL)
    {
        return 1;
    }

    fread(&numeroEmprestimos, sizeof(int), 1, fpEmprestimo);
    fclose(fpEmprestimo);

    if (numeroEmprestimos == 0)
    {
        return 1;
    }
    return 0;
}

int inicializaArquivos()
{
    printf("Inicializando arquivos.");
    int numeroRegistros = 0;

    FILE *fpLivro = fopen(arqLivro, "wb");
    FILE *fpUsuario = fopen(arqUsuario, "wb");
    FILE *fpEmprestimo = fopen(arqEmprestimo, "wb");
    if (fpLivro == NULL || fpUsuario == NULL || fpEmprestimo == NULL)
    {
        printf("Erro ao inicializar arquivos.\n");

        fclose(fpLivro);
        fclose(fpUsuario);
        fclose(fpEmprestimo);

        return 1;
    }

    fwrite(&numeroRegistros, sizeof(int), 1, fpLivro);
    fwrite(&numeroRegistros, sizeof(int), 1, fpUsuario);
    fwrite(&numeroRegistros, sizeof(int), 1, fpEmprestimo);

    fclose(fpLivro);
    fclose(fpUsuario);
    fclose(fpEmprestimo);

    return 0;
}