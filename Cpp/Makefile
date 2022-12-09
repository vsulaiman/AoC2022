CXX = g++
INCLUDEFLAGS = -I solutions/
LDLIBS =
CXXFLAGS = $(WARNINGS) -std=c++17 $(OPT)
WARNINGS = -Wall -Wno-sign-compare
OPT = -march=native -O3
SRCS = main.cpp \
		solutions/src/day01.cpp solutions/src/day02.cpp solutions/src/day03.cpp solutions/src/day04.cpp solutions/src/day05.cpp \
		solutions/src/day06.cpp solutions/src/day07.cpp solutions/src/day08.cpp solutions/src/day09.cpp
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