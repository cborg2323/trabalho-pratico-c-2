#ifndef FUNCOES_ALOCACAO_H
#define FUNCOES_ALOCACAO_H

#include "structs.h"

int verificaAlocacaoLivros(Livro **lv, int n, int *n_aloc);

int verificaAlocacaoUsuarios(Usuario **us, int n, int *n_aloc);

int verificaAlocacaoEmprestimos(Emprestimo **emp, int n, int *n_aloc);

int inicializaEstruturaLivros(Livro **lv);

int inicializaEstruturaUsuarios(Usuario **us);

int inicializaEstruturaEmprestioms(Emprestimo **emp);

#endif