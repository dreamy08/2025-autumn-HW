CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic

BUILD_DIR := build

# расширение бинарников под ОС
EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif

# --- HW1 ---
HW1_SRC := HW1/main.cpp
HW1_BIN := $(BUILD_DIR)/hw1$(EXE)

# --- Tests (HW2 + HW3) ---
TEST_SRCS := tests/hw2_text_editor_test.cpp tests/hw3_bank_test.cpp
TEST_BIN := $(BUILD_DIR)/hw_tests$(EXE)

.PHONY: all build run test clean

all: build

build: $(HW1_BIN)

$(HW1_BIN): $(HW1_SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(HW1_SRC) -o $(HW1_BIN)

run: build
	./$(HW1_BIN) < HW1/input.txt

test:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I. $(TEST_SRCS) -o $(TEST_BIN) -lgtest -lgtest_main -pthread
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR)
