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

    if (arquivoUsuariosVazio())
    {
        // cadastro usuarios
        printf("Cadastrar usuarios;");
    }

    if (arquivoEmprestimosVazio())
    {
        // cadastro emprestimos
        printf("Cadastrar emprestimos;");
    }
    else
    {
        carregarLivros(&lv, &n_livro);
        carregarUsuarios(&us, &n_usuario);
        carregarEmprestimos(&emp, &n_emprestimo);
    }

    return 0;
}