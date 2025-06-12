# Kompilator i flagi
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -MMD -MP

# Ścieżki
SRC_DIR := src
INC_DIR := include
OBJ_DIR := build
BIN := main

# Pliki źródłowe i obiektowe
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
MAIN := main.cpp
MAIN_OBJ := $(OBJ_DIR)/main.o

# Pliki zależności
DEPS := $(OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

# Domyślny cel
all: $(BIN)
	@echo "---> Uruchamianie programu <---"
	@./$(BIN)

# Tworzenie pliku wykonywalnego
$(BIN): $(MAIN_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Kompilacja plików .cpp do .o (z generowaniem zależności)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(MAIN)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Dołącz pliki zależności, jeśli istnieją
-include $(DEPS)

.PHONY: all clean
