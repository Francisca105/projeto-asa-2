C = gcc
CFLAGS = -std=c11 -O3 -Wall
C++ = g++
C++FLAGS = -std=c++11 -O3 -Wall

OUT_FILE=proj
MAIN_FILE=scc.cpp

all: main idk p2

main: $(MAIN_FILE)
	$(C++) $(C++FLAGS) -o $(OUT_FILE) $(MAIN_FILE) -lm

idk: idk.cpp
	$(C++) $(C++FLAGS) -o idk idk.cpp -lm

p2: p2.cpp
	$(C++) $(C++FLAGS) -o p2 p2.cpp -lm

.PHONY: clean
clean:
	rm -f $(OUT_FILE) idk p2

run:
	@./$(OUT_FILE)