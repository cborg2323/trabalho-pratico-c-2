#include <stdio.h>
#include <stdlib.h>

#include "../include/funcoes-alocacao.h"
#include "../include/funcoes-cadastro.h"
#include "../include/funcoes-inic-arquivo.h"
#include "../include/funcoes-salva-carrega-arq.h"

int main()
{
    Livro *lv = NULL;
    Usuario *us = NULL;
    Emprestimo *emp = NULL;
    int n_livro, n_usuario, n_emprestimo;
    int n_aloc_livro, n_aloc_usuario, n_aloc_emprestimo;

    n_livro = 0;
    n_usuario = 0;
    n_emprestimo = 0;

    n_aloc_livro = ALOC_INICIAL;
    n_aloc_usuario = ALOC_INICIAL;
    n_aloc_emprestimo = ALOC_INICIAL;

    if (!arquivosInicializados())
    {
        inicializaArquivos();
    }

    if (arquivoLivrosVazio())
    {
        // cadastro livros

        inicializaEstruturaLivros(&lv);
        cadastroLivro(&lv, &n_livro);
        printf("Número de livros: %d\n", n_livro);
    }
    else
    {
        carregarLivros(&lv, &n_livro);
    }

    if (arquivoUsuariosVazio())
    {
        inicializaEstruturaUsuarios(&us);
        cadastroUsuario(&us, &n_usuario);
    }
    else
    {
        carregarUsuarios(&us, &n_usuario);
    }

    if (arquivoEmprestimosVazio())
    {
        printf("Cadastrar emprestimos.");
    }
    else
    {
        carregarEmprestimos(&emp, &n_emprestimo);
    }

    salvarLivros(&lv, n_livro);
    salvarUsuarios(&us, n_usuario);
    salvarEmprestimos(&emp, n_emprestimo);

    return 0;
}