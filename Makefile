SRC_DIR := src
BUILD_DIR := build
TEST_DIR := tests
INC_DIR := include

CC := gcc
CFLAGS := -Wall -Wextra -std=c17 -I$(INC_DIR)
LDFLAGS := -lcriterion -lcurl

# Tous les fichiers source
ALL_SRC := $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Fichiers sans main.c (pour tests)
SRC := $(filter-out $(SRC_DIR)/main.c, $(ALL_SRC))

# Objets pour le binaire principal
FULL_OBJ := $(ALL_SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Objets pour tests uniquement
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Binaire principal
BIN := $(BUILD_DIR)/app

# Tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_BIN := $(BUILD_DIR)/tests

# Règle par défaut
.PHONY: all
all: $(BIN)

# Compilation du programme principal (avec main.c)
$(BIN): $(FULL_OBJ)
	clear
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation des .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation et exécution des tests
.PHONY: test
test: $(TEST_BIN)
	clear
	@echo "Lancement des tests Criterion..."
	@./$(TEST_BIN)

# Binaire de test (sans main.c)
$(TEST_BIN): $(TEST_SRC) $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Nettoyage
.PHONY: clean
clean:
	clear
	rm -rf $(BUILD_DIR)

# Exécution du programme
.PHONY: run
run: all
	./$(BIN) 192.168.1.1
