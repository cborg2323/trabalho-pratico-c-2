# Sistema de Gerenciamento de Biblioteca

## 📌 Sobre o Projeto
Este projeto é um sistema de gerenciamento de biblioteca em C que permite cadastrar, listar, alterar e excluir livros, usuários e empréstimos. Ele utiliza arquivos binários para armazenar os dados e possibilita a persistência das informações entre execuções.

## 🚀 Funcionalidades
- 📚 **Gerenciamento de Livros:**
  - Cadastrar novos livros
  - Listar livros cadastrados
  - Alterar informações de livros
  - Excluir livros

- 👥 **Gerenciamento de Usuários:**
  - Cadastrar novos usuários
  - Listar usuários cadastrados
  - Alterar informações dos usuários
  - Excluir usuários

- 🔄 **Gerenciamento de Empréstimos:**
  - Registrar novos empréstimos
  - Listar empréstimos cadastrados
  - Registrar devolução de livros

## 🛠️ Como Compilar e Executar
### Requisitos
- Compilador GCC instalado
- Sistema operacional Linux ou Windows com MinGW

### Compilação
Use o `Makefile` para compilar o projeto. No terminal, execute:
```bash
make
```
Isso gerará um executável chamado `programa`.

### Execução
Após a compilação, execute o programa com:
```bash
./programa
```

## 🐛 Depuração com GDB
Para compilar com símbolos de depuração, utilize:
```bash
make clean && make
```
Para executar com o GDB:
```bash
gdb ./programa
```

## 📁 Estrutura do Projeto
```
/
├── src/                              # Código-fonte
│   ├── main.c                        # Programa principal
│   ├── constantes.c                  # Constantes com nomes de arquivo e alocação inicial
│   ├── funcoes-alocao.c              # Funções para gerenciamento de memória
│   ├── funcoes-cadastro.c            # Funções CRUD
│   ├── funcoes-inic-arquivo.c        # Funções para inicialização de arquivos
│   ├── funcoes-listagem.c            # Funções para listagem e consulta
│   ├── funcoes-salva-carrega-arq.c   # Funções de manipulação de arquivos
├── include/                          # Arquivos de cabeçalho e estrutura
│   ├── structs.h                     # Definição das estruturas
│   ├── funcoes-alocao.h
│   ├── funcoes-cadastro.h
│   ├── funcoes-inic-arquivo.h
│   ├── funcoes-listagem.h
│   ├── funcoes-salva-carrega-arq.h
├── Makefile                          # Automação da compilação
├── README.md                         # Documentação do projeto
```

## 👨‍💻 Autor
- Nome: Clovis Nunes
- Contato: clobnjr@ufu.br

