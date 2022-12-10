CXX = g++
INCLUDEFLAGS = -I solutions/ -I/usr/local/opt/openssl@3/include
LDLIBS = -lssl -lcrypto
CXXFLAGS = $(WARNINGS) -std=c++17 $(OPT)
WARNINGS = -Wall -Wno-sign-compare
OPT = -march=native -O3
SRCS = main.cpp
SRCS += $(wildcard solutions/src/*.cpp)
OBJS=$(addprefix build/, $(subst .cpp,.o,$(SRCS)))

NUM_LIST := $(shell seq 1 9)
INPUTS := $(foreach n, $(NUM_LIST), $(shell printf '../Inputs/input%02d.txt' $(n)))

all: build/main $(INPUTS) | build/solutions/src
	./build/main > output.txt

build/main: $(OBJS) | build
	$(CXX) $(INCLUDEFLAGS) -o build/main $(OBJS) $(CXXFLAGS) $(LDLIBS)

build/%.o: %.cpp | build
	$(CXX) $(INCLUDEFLAGS) $< -o $@ -c $(CXXFLAGS)

../Inputs/input%.txt: build/download_inputs | ../Inputs
	@echo "Downloading input $*"
	@./build/download_inputs $*

build/download_inputs: build/download_inputs.o | build
	$(CXX) $(INCLUDEFLAGS) -o build/download_inputs build/download_inputs.o $(CXXFLAGS) $(LDLIBS)

build/download_inputs.o: download_inputs.cpp | build
	$(CXX) $(INCLUDEFLAGS) $< -o $@ -c $(CXXFLAGS)

build:
	mkdir -p build
build/solutions/src: build
	mkdir -p build/solutions/src
../Inputs:
	mkdir -p ../Inputs