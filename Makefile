CXX ?= g++
CXXFLAGS ?= -std=c++20 -O2 -Wall -Wextra -Wpedantic -Werror

APP := hw1
SRC := $(wildcard HW1/*.cpp)
BIN := build/$(APP)

.PHONY: build run clean format-check sanitize

build:
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

run: build
	./$(BIN) HW1/input.txt build/out.txt
	test -f build/out.txt

format-check:
	clang-format --dry-run --Werror HW1/*.cpp

sanitize:
	mkdir -p build
	$(CXX) -std=c++20 -O1 -g -Wall -Wextra -Wpedantic -Werror \
		-fsanitize=address,undefined -fno-omit-frame-pointer \
		$(SRC) -o $(BIN)
	./$(BIN) HW1/input.txt build/out.txt

clean:
	rm -rf build
