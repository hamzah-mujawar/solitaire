# Variables
GTEST_DIR = $(HOME)/googletest/googletest
CXX = g++
CC = gcc
CFLAGS = -Wall -g -lncurses
CXXFLAGS = -I$(GTEST_DIR)/include -pthread
LDFLAGS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -lncurses

# Targets
all: run_tests

run_tests: windows_test.o windows.o common.o
	$(CXX) -o run_tests windows_test.o windows.o common.o $(LDFLAGS)
	./run_tests

windows.o: src/windows.c include/windows.h include/common.h
	$(CC) $(CFLAGS) -c src/windows.c -o windows.o

windows_test.o: tests/windows_test.cpp
	$(CXX) $(CXXFLAGS) -c tests/windows_test.cpp -o windows_test.o

common.o: src/common.c include/common.h
	$(CC) $(CFLAGS) -c src/common.c -o common.o

clean:
	rm -f *.o run_tests

.PHONY: clean run_tests

