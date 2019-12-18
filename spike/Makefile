all: civetweb civetserver rover
C++FLAGS = -std=c++17 -Wall
.PHONY: all C++FLAGS LDFLAGS

civetweb: lib/civetweb_min/src/civetweb.c
	clang -c lib/civetweb_min/src/civetweb.c -o build/civetweb.o

civetserver: lib/civetweb_min/src/CivetServer.cpp
	clang++ -c $(CXXFLAGS) lib/civetweb_min/src/CivetServer.cpp -o build/civetserver.o

rover: src/main.cpp 
	clang++ $(CXXFLAGS) src/main.cpp build/civetweb.o build/civetserver.o -o bin/rover

