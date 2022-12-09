CXX = g++
INCLUDEFLAGS = -I solutions/
LDLIBS =
CXXFLAGS = $(WARNINGS) -std=c++17 $(OPT)
WARNINGS = -Wall -Wno-sign-compare
OPT = -march=native -O3
SRCS = main.cpp \
		solutions/src/day01.cpp solutions/src/day02.cpp solutions/src/day03.cpp solutions/src/day04.cpp solutions/src/day05.cpp \
		solutions/src/day06.cpp solutions/src/day07.cpp solutions/src/day08.cpp solutions/src/day09.cpp solutions/src/day10.cpp \
		solutions/src/day11.cpp solutions/src/day12.cpp solutions/src/day13.cpp solutions/src/day14.cpp solutions/src/day15.cpp \
		solutions/src/day16.cpp solutions/src/day17.cpp solutions/src/day18.cpp solutions/src/day19.cpp solutions/src/day20.cpp \
		solutions/src/day21.cpp solutions/src/day22.cpp solutions/src/day23.cpp solutions/src/day24.cpp solutions/src/day25.cpp
OBJS=$(addprefix build/, $(subst .cpp,.o,$(SRCS)))

all: build build/solutions/src build/main ../Inputs/input*.txt
	./build/main > output.txt

build/main: $(OBJS) | build
	$(CXX) $(INCLUDEFLAGS) -o build/main $(OBJS) $(CXXFLAGS) $(LDLIBS)

build/%.o: %.cpp | build
	$(CXX) $(INCLUDEFLAGS) $< -o $@ -c $(CXXFLAGS)

build:
	mkdir -p build
build/solutions/src: build
	mkdir -p build/solutions/src