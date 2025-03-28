# Nome do executável
EXEC = programa

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -I$(INC_DIR) -Wall -Wextra -g

# Lista de arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Lista de arquivos objeto (.o) na pasta OBJ_DIR
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Regra para compilar arquivos .c em .o dentro da pasta OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar a pasta OBJ_DIR se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpa os arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Força recompilação total
rebuild: clean $(EXEC)