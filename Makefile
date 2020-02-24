
src = build/io.o build/configs.o build/spatial-awareness.o build/planet.o build/robot.o
testCases = build/io-unit-tests.o build/config-unit-tests.o build/spatial-unit-tests.o build/planet-unit-tests.o build/robot-unit-tests.o
tests = $(testCases) unit-tests-main unit-test-runner
all: $(src) $(tests) main simulation

comp = clang++
C++FLAGS= -std=c++17 -Wall -Wc++11-extensions
.PHONY: all C++FLAGS clean

build/io.o: src/io.cpp
	$(comp) $(C++FLAGS) -c src/io.cpp -o build/io.o

build/configs.o: src/configs/startup-config.cpp
	$(comp) $(C++FLAGS) -c src/configs/startup-config.cpp -o build/configs.o

build/spatial-awareness.o: src/simulation/spatial-awareness.cpp
	$(comp) $(C++FLAGS) -c src/simulation/spatial-awareness.cpp -o build/spatial-awareness.o

build/planet.o: src/simulation/planet.cpp
	$(comp) $(C++FLAGS) -c src/simulation/planet.cpp -o build/planet.o

build/robot.o: src/simulation/robot.cpp
	$(comp) $(C++FLAGS) -c src/simulation/robot.cpp -o build/robot.o

build/io-unit-tests.o: tests/unit/io.cpp
	$(comp) $(C++FLAGS) -Wno-writable-strings -c tests/unit/io.cpp -o build/io-unit-tests.o

build/config-unit-tests.o: tests/unit/startup-config.cpp
	$(comp) $(C++FLAGS) -Wno-writable-strings -c tests/unit/startup-config.cpp -o build/config-unit-tests.o

build/spatial-unit-tests.o: tests/unit/spatial-awareness.cpp
	$(comp) $(C++FLAGS) -Wno-writable-strings -c tests/unit/spatial-awareness.cpp -o build/spatial-unit-tests.o

build/planet-unit-tests.o: tests/unit/planet.cpp
	$(comp) $(C++FLAGS) -Wno-writable-strings -c tests/unit/planet.cpp -o build/planet-unit-tests.o
	
build/robot-unit-tests.o: tests/unit/robot.cpp
	$(comp) $(C++FLAGS) -Wno-writable-strings -c tests/unit/robot.cpp -o build/robot-unit-tests.o

unit-tests-main: tests/main.cpp
	$(comp) $(C++FLAGS) -c tests/main.cpp -o build/unit-tests-main.o

unit-test-runner: $(src) $(testCases)
	$(comp) $(C++FLAGS) $(src) $(testCases) build/unit-tests-main.o -o bin/unit-tests

main: src/main.cpp
	$(comp) $(C++FLAGS) -c src/main.cpp -o build/main.o

simulation: $(src) 
	$(comp) $(C++FLAGS) $(src) build/main.o -o bin/simulation

clean:
	rm build/*
