C = gcc
CFLAGS = -std=c11 -O3 -Wall
C++ = g++
C++FLAGS = -std=c++11 -O3 -Wall

OUT_FILE=proj
MAIN_FILE=projeto.cpp

all: main

main: projeto.cpp
	$(C++) $(C++FLAGS) -o $(OUT_FILE) $(MAIN_FILE) -lm

.PHONY: clean
clean:
	rm -f $(OUT_FILE)

run:
	@./$(OUT_FILE)