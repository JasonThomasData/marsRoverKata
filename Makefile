CXXFLAGS = -std=c++17 -Wall

rover: src/main.cpp 
	clang++ $(CXXFLAGS) src/main.cpp -o bin/rover
