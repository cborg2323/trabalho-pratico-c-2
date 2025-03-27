#ifndef FUNCOES_CADASTRO_H
#define FUNCOES_CADASTRO_H

#include "structs.h"
#include "funcoes-alocacao.h"

int cadastroLivro(Livro **lv, int *n, int *n_aloc);

int buscaLivro(Livro *lv, int n, int codigoLivroBuscado);

int cadastroUsuario(Usuario **us, int *n, int *n_aloc);

int buscaUsuario(Usuario *us, int n, int idUsuarioBuscado);

int cadastroEmprestimo(Emprestimo **emp, int *n, int *n_aloc, Livro *lv, int n_livro, Usuario *us, int n_usuario);

int alterarLivro(Livro **lv, int n);

#endif