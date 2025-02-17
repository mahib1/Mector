CC = g++
CFLAGS = -std=c++17
SRC = main.cpp
OBJ_DIR = obj
BIN_DIR = bin
ASM_DIR = asm
PRE_DIR = pre

TARGET = $(BIN_DIR)/main

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(ASM_DIR):
	mkdir -p $(ASM_DIR)

$(PRE_DIR):
	mkdir -p $(PRE_DIR)

$(OBJ_DIR)/main.o: main.cpp arrayBuilder.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c main.cpp -o $@

$(ASM_DIR)/main.s: main.cpp | $(ASM_DIR)
	$(CC) $(CFLAGS) -S main.cpp -o $@

$(PRE_DIR)/main.i: main.cpp | $(PRE_DIR)
	$(CC) $(CFLAGS) -E main.cpp -o $@

$(TARGET): $(OBJ_DIR)/main.o | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

all: $(TARGET) $(ASM_DIR)/main.s $(PRE_DIR)/main.i

run: ./bin/main 
	./bin/main

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(ASM_DIR) $(PRE_DIR)

.PHONY: all clean
PHONY: all clean
