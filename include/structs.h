#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[100];
    int anoPublicacao;
} Livro;

typedef struct
{
    int id;
    char nome[100];
    char email[100];
    int idade;
} Usuario;

typedef struct
{
    int codigoLivro;
    int idUsuario;
    Data dataEmprestimo;
} Emprestimo;

extern const int ALOC_INICIAL;
extern const char arqLivro[25];
extern const char arqUsuario[25];
extern const char arqEmprestimo[25];

#endif