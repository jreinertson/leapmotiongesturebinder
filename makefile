all: leap

leap: leap.cpp
	g++ -g -o $@ $^ libLeap.so