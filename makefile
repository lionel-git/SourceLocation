CXX=g++
CXXVER=c++20


CLANGVERGCC=
MACHINE_ID=$(shell /usr/bin/cat /etc/machine-id)
ifeq ($(MACHINE_ID), 0e77c5947a5b461286b81059bba0e7e5)
 CLANGVERGCC=--gcc-install-dir=/usr/lib/gcc/aarch64-linux-gnu/13
endif



all: main main_clang

main : main.cpp
	$(CXX) -std=$(CXXVER) main.cpp -o main

main_clang : main.cpp
	clang++ -std=$(CXXVER) $(CLANGVERGCC) main.cpp -o main_clang

clean:
	rm -f *.o ./main ./main_clang ./main_icx

