CXXC = g++
CXXFLAGS = -std=c++11 -O3 -Wall

all: main

main: gen_tuganet.cpp
	$(CXX) $(CXXFLAGS) -o gen gen_tuganet.cpp -lm

.PHONY: clean
clean:
	rm -f main gen