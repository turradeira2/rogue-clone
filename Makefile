CC = gcc

#Flags para o compilador
CFLAGS = -Wall -Wextra -pedantic -std=c2x -Iinclude

#Nome output do exec
TARGET = rogue_clone

#Nome das Pastas
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

#<- referencia a pasta onde estão todos os codigos .c
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
