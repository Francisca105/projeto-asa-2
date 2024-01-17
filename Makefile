C++ = g++
C++FLAGS = -std=c++11 -O3 -Wall

p2: p2.cpp
	$(C++) $(C++FLAGS) -o p2 p2.cpp -lm

.PHONY: clean
clean:
	rm -f p2

run:
	@./p2