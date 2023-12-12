C = gcc
CFLAGS = -std=c11 -O3 -Wall
C++ = g++
C++FLAGS = -std=c++11 -O3 -Wall

OUT_FILE=proj
MAIN_FILE=scc.cpp

all: main idk

main: $(MAIN_FILE)
	$(C++) $(C++FLAGS) -o $(OUT_FILE) $(MAIN_FILE) -lm

idk: idk.cpp
	$(C++) $(C++FLAGS) -o idk idk.cpp -lm

.PHONY: clean
clean:
	rm -f $(OUT_FILE) idk

run:
	@./$(OUT_FILE)