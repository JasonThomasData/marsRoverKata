
src = build/io.o build/planet.o build/robot.o
testCases = build/io-unit-tests.o build/planet-unit-tests.o build/robot-unit-tests.o
tests = $(testCases) unit-tests-main unit-test-runner
all: $(src) $(tests) main simulation

C++FLAGS= -std=c++17 -Wall -Wc++11-extensions
.PHONY: all C++FLAGS

build/io.o: src/io.cpp
	clang++ $(C++FLAGS) -c src/io.cpp -o build/io.o

build/planet.o: src/simulation/planet.cpp
	clang++ $(C++FLAGS) -c src/simulation/planet.cpp -o build/planet.o

build/robot.o: src/simulation/robot.cpp
	clang++ $(C++FLAGS) -c src/simulation/robot.cpp -o build/robot.o

build/io-unit-tests.o: tests/unit/io.cpp
	clang++ $(C++FLAGS) -Wno-writable-strings -c tests/unit/io.cpp -o build/io-unit-tests.o

build/planet-unit-tests.o: tests/unit/planet.cpp
	clang++ $(C++FLAGS) -Wno-writable-strings -c tests/unit/planet.cpp -o build/planet-unit-tests.o
	
build/robot-unit-tests.o: tests/unit/robot.cpp
	clang++ $(C++FLAGS) -Wno-writable-strings -c tests/unit/robot.cpp -o build/robot-unit-tests.o

unit-tests-main: tests/main.cpp
	clang++ $(C++FLAGS) -c tests/main.cpp -o build/unit-tests-main.o

unit-test-runner: $(src) $(testCases)
	clang++ $(C++FLAGS) $(src) $(testCases) build/unit-tests-main.o -o bin/unit-tests

main: src/main.cpp
	clang++ $(C++FLAGS) -c src/main.cpp -o build/main.o

simulation: $(src) 
	clang++ $(C++FLAGS) $(src) build/main.o -o bin/simulation
