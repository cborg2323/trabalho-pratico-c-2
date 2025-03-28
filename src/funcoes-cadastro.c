#include <stdio.h>
#include <time.h>

#include "../include/funcoes-cadastro.h"

int cadastroLivro(Livro **lv, int *n, int *n_aloc)
{
    verificaAlocacaoLivros(lv, *n, n_aloc);

    printf("\n\nDigite o código do livro: ");
    scanf("%d", &(*lv)[*n].codigo);
    printf("Digite o título do livro: ");
    getchar();
    fgets((*lv)[*n].titulo, 100, stdin);
    printf("Digite o autor do livro: ");
    fgets((*lv)[*n].autor, 100, stdin);
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &(*lv)[*n].anoPublicacao);

    (*n)++;

    return 0;
}

int buscaLivro(Livro *lv, int n, int codigoLivroBuscado)
{
    for (int i = 0; i < n; i++)
    {
        if (lv[i].codigo == codigoLivroBuscado)
        {
            return i;
        }
    }

    return -1;
}

int cadastroUsuario(Usuario **us, int *n, int *n_aloc)
{
    verificaAlocacaoUsuarios(us, *n, n_aloc);

    printf("\n\nDigite o ID do usuário: ");
    scanf("%d", &(*us)[*n].id);
    printf("Digite o nome do usuário: ");
    getchar();
    fgets((*us)[*n].nome, 100, stdin);
    printf("Digite o email do usuário: ");
    fgets((*us)[*n].email, 100, stdin);
    printf("Digite a idade do usuário: ");
    scanf("%d", &(*us)[*n].idade);

    (*n)++;

    return 0;
}

int buscaUsuario(Usuario *us, int n, int idUsuarioBuscado)
{
    for (int i = 0; i < n; i++)
    {
        if (us[i].id == idUsuarioBuscado)
        {
            return i;
        }
    }

    return -1;
}

int cadastroEmprestimo(Emprestimo **emp, int *n, int *n_aloc, Livro *lv, int n_livro, Usuario *us, int n_usuario)
{
    verificaAlocacaoEmprestimos(emp, *n, n_aloc);

    time_t t = time(NULL);
    int codigoLivro, idUsuario;
    printf("\nDigite o código do livro: ");
    scanf("%d", &codigoLivro);
    printf("Digite o ID do usuário: ");
    scanf("%d", &idUsuario);

    int indiceLivro = buscaLivro(lv, n_livro, codigoLivro);
    int indiceUsuario = buscaUsuario(us, n_usuario, idUsuario);

    if (indiceLivro != -1 && indiceUsuario != -1)
    {
        (*emp)[*n].codigoLivro = codigoLivro;
        (*emp)[*n].idUsuario = idUsuario;

        struct tm tm = *localtime(&t);
        (*emp)[*n].dataEmprestimo.dia = tm.tm_mday;
        (*emp)[*n].dataEmprestimo.mes = tm.tm_mon + 1;
        (*emp)[*n].dataEmprestimo.ano = tm.tm_year + 1900;

        (*n)++;

        return 0;
    }

    return 1;
}

int buscaEmprestimo(Emprestimo *emp, int n, int codLivroBuscado, int idUsuarioBuscado)
{
    for (int i = 0; i < n; i++)
    {
        if (emp[i].codigoLivro == codLivroBuscado && emp[i].idUsuario == idUsuarioBuscado)
        {
            return i;
        }
    }

    return -1;
}

int alterarLivro(Livro **lv, int n)
{
    int codigoLivro;
    printf("\nDigite o código do livro a ser alterado: ");
    scanf("%d", &codigoLivro);

    int indiceLivroBuscado = buscaLivro(*lv, n, codigoLivro);

    if (indiceLivroBuscado != -1)
    {
        printf("Digite o título do livro: ");
        getchar();
        fgets((*lv)[indiceLivroBuscado].titulo, 100, stdin);
        printf("Digite o autor do livro: ");
        fgets((*lv)[indiceLivroBuscado].autor, 100, stdin);
        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &(*lv)[indiceLivroBuscado].anoPublicacao);

        return 0;
    }

    return 1;
}

int alterarUsuario(Usuario **us, int n)
{
    int idUsuarioBuscado;
    printf("\nDigite o ID do usuário a ser alterado: ");
    scanf("%d", &idUsuarioBuscado);

    int indiceUsuarioBuscado = buscaUsuario(*us, n, idUsuarioBuscado);

    if (indiceUsuarioBuscado != -1)
    {
        printf("Digite o nome do usuário: ");
        getchar();
        fgets((*us)[indiceUsuarioBuscado].nome, 100, stdin);
        printf("Digite o email do usuário: ");
        fgets((*us)[indiceUsuarioBuscado].email, 100, stdin);
        printf("Digite a idade do usuário: ");
        scanf("%d", &(*us)[indiceUsuarioBuscado].idade);

        return 0;
    }

    return 1;
}

int alterarEmprestimo(Emprestimo **emp, int n, Livro *lv, int n_livro, Usuario *us, int n_usuario)
{
    int codigoLivroAntigo, idUsuarioAntigo, codigoLivroNovo, idUsuarioNovo;
    int indiceEmprestimoBuscado, indiceLivroNovo, indiceUsuarioNovo;
    printf("\nDigite os dados do empréstimo a ser alterado\n");
    printf("Código do livro: ");
    scanf("%d", &codigoLivroAntigo);
    printf("ID do usuário: ");
    scanf("%d", &idUsuarioAntigo);

    indiceEmprestimoBuscado = buscaEmprestimo(*emp, n, codigoLivroAntigo, idUsuarioAntigo);

    if (indiceEmprestimoBuscado != -1)
    {
        printf("\nDigite os dados do novo empréstimo\n");
        printf("Código do livro: ");
        scanf("%d", &codigoLivroNovo);
        printf("ID do usuário: ");
        scanf("%d", &idUsuarioNovo);

        indiceLivroNovo = buscaLivro(lv, n_livro, codigoLivroNovo);
        indiceUsuarioNovo = buscaUsuario(us, n_usuario, idUsuarioNovo);

        if (indiceLivroNovo != -1 && indiceUsuarioNovo != -1)
        {
            (*emp)[indiceEmprestimoBuscado].codigoLivro = lv[indiceLivroNovo].codigo;
            (*emp)[indiceEmprestimoBuscado].idUsuario = us[indiceUsuarioNovo].id;

            return 0;
        }

        printf("Código do livro e/ou ID do usuário não encontrado.\n");
        
        return 1;
    }

    printf("Dados do emprestimo não encontrados.\n");

    return 1;
}