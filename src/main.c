#include <stdio.h>
#include <stdlib.h>

#include "../include/funcoes-alocacao.h"
#include "../include/funcoes-cadastro.h"
#include "../include/funcoes-inic-arquivo.h"
#include "../include/funcoes-salva-carrega-arq.h"
#include "../include/funcoes-listagem.h"

int main()
{
    Livro *lv = NULL;
    Usuario *us = NULL;
    Emprestimo *emp = NULL;
    int n_livro, n_usuario, n_emprestimo;
    int n_aloc_livro, n_aloc_usuario, n_aloc_emprestimo;
    int opcao;

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
        inicializaEstruturaLivros(&lv);
        cadastroLivro(&lv, &n_livro, &n_aloc_livro);
        printf("Número de livros: %d\n", n_livro);
    }
    else
    {
        carregarLivros(&lv, &n_livro, &n_aloc_livro);
    }

    if (arquivoUsuariosVazio())
    {
        inicializaEstruturaUsuarios(&us);
        cadastroUsuario(&us, &n_usuario, &n_aloc_usuario);
    }
    else
    {
        carregarUsuarios(&us, &n_usuario, &n_aloc_usuario);
    }

    if (arquivoEmprestimosVazio())
    {
        inicializaEstruturaEmprestioms(&emp);
    }
    else
    {
        carregarEmprestimos(&emp, &n_emprestimo, &n_aloc_emprestimo);
    }

    do
    {
        printf("\n--- Menu Principal ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Cadastrar Empréstimo\n");
        printf("4. Listar Livros\n");
        printf("5. Listar Usuários\n");
        printf("6. Listar Empréstimos\n");
        printf("7. Alterar Livro\n");
        printf("8. Alterar Usuário\n");
        printf("8. Alterar Empréstimo\n");
        printf("0. Salvar e Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastroLivro(&lv, &n_livro, &n_aloc_livro);
            break;
        case 2:
            cadastroUsuario(&us, &n_usuario, &n_aloc_usuario);
            break;
        case 3:
            cadastroEmprestimo(&emp, &n_emprestimo, &n_aloc_emprestimo, lv, n_livro, us, n_usuario);
            break;
        case 4:
            listarLivros(lv, n_livro);
            break;
        case 5:
            listarUsuarios(us, n_usuario);
            break;
        case 6:
            listarEmprestimos(emp, n_emprestimo, lv, n_livro, us, n_usuario);
            break;
        case 7:
            alterarLivro(&lv, n_livro);
            break;
        case 0:
            salvarLivros(lv, n_livro);
            salvarUsuarios(us, n_usuario);
            salvarEmprestimos(emp, n_emprestimo);
            printf("Dados salvos. Saindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}