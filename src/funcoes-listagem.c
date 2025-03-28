#include <stdio.h>

#include "../include/funcoes-listagem.h"

void listarLivros(Livro *lv, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nCódigo do livro: %d\n", lv[i].codigo);
        printf("Título do livro: %s", lv[i].titulo);
        printf("Autor do livro: %s", lv[i].autor);
        printf("Ano de publicação do livro: %d\n\n", lv[i].anoPublicacao);
    }
}

void listarUsuarios(Usuario *us, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nID do usuário: %d\n", us[i].id);
        printf("Nome do usuário: %s", us[i].nome);
        printf("Email do usuário: %s", us[i].email);
        printf("Idade do usuário: %d\n\n", us[i].idade);
    }
}

void listarEmprestimos(Emprestimo *emp, int n, Livro *lv, int n_livro, Usuario *us, int n_usuario)
{
    int indiceUsuario, indiceLivro;

    for (int i = 0; i < n; i++)
    {
        indiceUsuario = buscaUsuario(us, n_usuario, emp[i].idUsuario);
        indiceLivro = buscaLivro(lv, n_livro, emp[i].codigoLivro);

        printf("\nData do empréstimo: %d/%d/%d\n", emp[i].dataEmprestimo.dia, emp[i].dataEmprestimo.mes, emp[i].dataEmprestimo.ano);
        printf("Usuário: %s", us[indiceUsuario].nome);
        printf("Email: %s", us[indiceUsuario].email);
        printf("Livro: %s", lv[indiceLivro].titulo);
        printf("Autor: %s", lv[indiceLivro].autor);
    }
}

void consultarLivro(Livro *lv, int n)
{
    int codLivroBuscado, indiceLivroBuscado;
    printf("\nDigite o código do livro: ");
    scanf("%d", &codLivroBuscado);

    indiceLivroBuscado = buscaLivro(lv, n, codLivroBuscado);

    if (indiceLivroBuscado != -1)
    {
        printf("Título: %s", lv[indiceLivroBuscado].titulo);
        printf("Autor: %s", lv[indiceLivroBuscado].autor);
        printf("Ano de publicação: %d\n", lv[indiceLivroBuscado].anoPublicacao);

        return 0;
    }

    printf("Livro não encontrado.\n");
    return 1;
}

void consultarUsuario(Usuario *us, int n)
{
    int idUsuarioBuscado, indiceUsuarioBuscado;
    printf("\nDigite o ID do usuário: ");
    scanf("%d", &idUsuarioBuscado);

    indiceUsuarioBuscado = buscaUsuario(us, n, idUsuarioBuscado);

    if (idUsuarioBuscado != -1)
    {
        printf("Nome: %s", us[indiceUsuarioBuscado].nome);
        printf("Email: %s", us[indiceUsuarioBuscado].email);
        printf("Idade: %d\n", us[indiceUsuarioBuscado].idade);

        return 0;
    }

    printf("Usuário não encontrado.\n");
    return 1;
}