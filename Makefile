# Nome do executável
EXEC = programa

# Diretórios
SRC_DIR = src
INC_DIR = include

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -I$(INC_DIR) -Wall -Wextra -g

# Lista de arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Lista de arquivos objeto (.o)
OBJS = $(SRCS:.c=.o)

# Regra principal
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Regra para compilar arquivos .c em .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos compilados
clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)

# Força recompilação total
rebuild: clean $(EXEC)