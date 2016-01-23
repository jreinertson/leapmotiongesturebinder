all: leap

leap: leap.cpp
	g++ -g -o $@ $^ /usr/lib/libLeap.so