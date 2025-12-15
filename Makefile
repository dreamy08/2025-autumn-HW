CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic

BUILD_DIR := build

# расширение бинарников под ОС
EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif

# Какая домашка собирается/запускается (по умолчанию HW1)
HW ?= 1

HW_SRC := HW$(HW)/main.cpp
HW_BIN := $(BUILD_DIR)/hw$(HW)$(EXE)

# --- Tests (по требованию: HW2 + HW3) ---
TEST_SRCS := tests/hw2_text_editor_test.cpp tests/hw3_bank_test.cpp
TEST_BIN := $(BUILD_DIR)/hw_tests$(EXE)

.PHONY: all build run test clean

all: build

build: $(HW_BIN)

$(HW_BIN): $(HW_SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(HW_SRC) -o $(HW_BIN)

# Для HW1 есть input.txt, для остальных — просто запускаем бинарник
run: build
ifeq ($(HW),1)
	./$(HW_BIN) < HW1/input.txt
else
	./$(HW_BIN)
endif

test:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I. $(TEST_SRCS) -o $(TEST_BIN) -lgtest -lgtest_main -pthread
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR)
