CXX = g++
INCLUDEFLAGS =
LDLIBS =
CXXFLAGS = $(WARNINGS) -std=c++17 $(OPT)
WARNINGS = -Wall -Wno-sign-compare
OPT = -march=native -O3
SRCS = solution.cpp
OBJS=$(addprefix build/, $(subst .cpp,.o,$(SRCS)))

all: build build/main input.txt
	./build/main input.txt > output.txt

build/main: $(OBJS) | build
	$(CXX) $(INCLUDEFLAGS) -o build/main $(OBJS) $(CXXFLAGS) $(LDLIBS)

build/%.o: %.cpp | build
	$(CXX) $(INCLUDEFLAGS) $< -o $@ -c $(CXXFLAGS)

build:
	mkdir -p build
