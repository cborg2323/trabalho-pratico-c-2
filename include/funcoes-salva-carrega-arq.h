#ifndef FUNCOES_SALVA_CARREGA_ARQ_H
#define FUNCOES_SALVA_CARREGA_ARQ_H

#include "structs.h"

int salvarLivros(Livro *lv, int n);

int carregarLivros(Livro **lv, int *n, int *n_aloc);

int salvarUsuarios(Usuario *us, int n);

int carregarUsuarios(Usuario **us, int *n, int *n_aloc);

int salvarEmprestimos(Emprestimo *emp, int n);

int carregarEmprestimos(Emprestimo **emp, int *n, int *n_aloc);

#endif