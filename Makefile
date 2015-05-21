# Check OS
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifneq (,$(findstring MINGW,$(uname_S)))
	X=.exe
endif

ifeq ($(OS),Windows_NT)
	X=.exe
endif

# Check CXX flag.
ifeq ($(CXX),clang++)
	CXX=clang++
else
	CXX=g++
endif

CXXFLAGS = -Wall -g -O2 -std=c++0x

all: demo$(X)

all_to_istream.o: all_to_istream.cpp
	@echo "==>Compiling all_to_istream.o..."
	$(CXX) -c $(CXXFLAGS) -o all_to_istream.o all_to_istream.cpp

demo$(X): all_to_istream.o
	@echo "==>Linking all_to_istream$(X)..."
	$(CXX) -o all_to_istream$(X) all_to_istream.o

clean: cleanoutput
	@echo "==>Clean Object and Executable..."
	rm -rf all_to_istream.o
	rm -rf all_to_istream$(X)
