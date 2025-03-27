#ifndef FUNCOES_LISTAGEM_H
#define FUNCOES_LISTAGEM_H

#include "structs.h"
#include "funcoes-cadastro.h"

void listarLivros(Livro *lv, int n);

void listarUsuarios(Usuario *us, int n);

void listarEmprestimos(Emprestimo *emp, int n, Livro *lv, int n_livro, Usuario *us, int n_usuario);

#endif