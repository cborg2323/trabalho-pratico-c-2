#include <stdio.h>

#include "../include/funcoes-cadastro.h"

int cadastroLivro(Livro **lv, int *n)
{
    printf("Digite o código do livro: ");
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

int cadastroUsuario(Usuario **us, int *n)
{
    printf("Digite o ID do usuário: ");
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