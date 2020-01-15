all: IO Planet tests main exe
tests: IO_unit_tests Planet_unit_tests unit_tests_main unit_test_runner

C++FLAGS= -std=c++17 -Wall
.PHONY: all C++FLAGS

IO: src/IO.cpp
	clang++ -c src/IO.cpp -o build/IO.o

Planet: src/simulation/Planet.cpp
	clang++ -c src/simulation/Planet.cpp -o build/Planet.o

IO_unit_tests: tests/unit/IO.cpp
	clang++ -c tests/unit/IO.cpp -o build/IOUnitTests.o

Planet_unit_tests: tests/unit/Planet.cpp
	clang++ -c tests/unit/Planet.cpp -o build/PlanetUnitTests.o

unit_tests_main: tests/main.cpp
	clang++ -c tests/main.cpp -o build/unitTestsMain.o

unit_test_runner: build/IO.o build/IOUnitTests.o build/PlanetUnitTests.o build/unitTestsMain.o
	clang++ $(C++FLAGS) build/IO.o build/IOUnitTests.o build/PlanetUnitTests.o build/unitTestsMain.o -o bin/unitTests

main: src/main.cpp
	clang++ -c src/main.cpp -o build/main.o

exe: build/IO.o build/Planet.o build/main.o
	clang++ $(C++FLAGS) build/IO.o build/Planet.o build/main.o -o bin/robot
