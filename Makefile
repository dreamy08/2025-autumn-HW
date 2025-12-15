CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic

BUILD_DIR := build
SRC := HW1/main.cpp

# На Windows делаем .exe, на Linux — без расширения
ifeq ($(OS),Windows_NT)
  BIN := $(BUILD_DIR)/hw1.exe
else
  BIN := $(BUILD_DIR)/hw1
endif

.PHONY: all build run clean

all: build

build: $(BIN)

$(BIN): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

run: build
	./$(BIN) < HW1/input.txt

clean:
	rm -rf $(BUILD_DIR)
