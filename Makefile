# Compiler
CC = clang
CFLAGS = -Wall -Wextra -O2 -std=c17

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Files
SRC = $(SRC_DIR)/advin.c
OBJ = $(OBJ_DIR)/advin.o
LIB = $(BIN_DIR)/libadvin.a

# Default target
all: $(LIB)

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile advin.c into object file
$(OBJ): $(SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Archive object file into static library
$(LIB): $(OBJ) | $(BIN_DIR)
	ar rcs $@ $^

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(LIB)

.PHONY: all clean
