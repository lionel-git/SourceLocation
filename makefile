CXX=g++
CXXVER=c++20

all: main main_clang

main : main.cpp
	$(CXX) -std=$(CXXVER) main.cpp -o main

main_clang : main.cpp
	clang++ --gcc-install-dir=/usr/lib/gcc/aarch64-linux-gnu/13 -std=$(CXXVER) main.cpp -o main_clang

clean:
	rm -f *.o ./main ./main_clang

