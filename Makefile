all: io planet robot tests main simulation
tests: io_unit_tests planet_unit_tests unit_tests_main unit_test_runner

C++FLAGS= -std=c++17 -Wall -Wc++11-extensions
.PHONY: all C++FLAGS

io: src/io.cpp
	clang++ $(C++FLAGS) -c src/io.cpp -o build/io.o

planet: src/simulation/planet.cpp
	clang++ $(C++FLAGS) -c src/simulation/planet.cpp -o build/planet.o

robot: src/simulation/robot.cpp
	clang++ $(C++FLAGS) -c src/simulation/robot.cpp -o build/robot.o

io_unit_tests: tests/unit/io.cpp
	clang++ $(C++FLAGS) -Wno-writable-strings -c tests/unit/io.cpp -o build/io-unit-tests.o

planet_unit_tests: tests/unit/planet.cpp
	clang++ $(C++FLAGS) -Wno-writable-strings -c tests/unit/planet.cpp -o build/planet-unit-tests.o

unit_tests_main: tests/main.cpp
	clang++ $(C++FLAGS) -c tests/main.cpp -o build/unit-tests-main.o

unit_test_runner: build/io.o build/planet.o build/io-unit-tests.o build/planet-unit-tests.o build/unit-tests-main.o
	clang++ $(C++FLAGS) build/io.o build/planet.o build/io-unit-tests.o build/planet-unit-tests.o build/unit-tests-main.o -o bin/unit-tests

main: src/main.cpp
	clang++ $(C++FLAGS) -c src/main.cpp -o build/main.o

simulation: build/io.o build/planet.o build/main.o
	clang++ $(C++FLAGS) build/io.o build/planet.o build/robot.o build/main.o -o bin/simulation
