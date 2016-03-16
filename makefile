MAKEFLAGS=-j4
CC=g++
CXXFLAGS+=-std=c++14

LDFLAGS=-lwt -lwthttp

SOURCES=$(wildcard */*.cpp)

EXECUTABLES=$(SOURCES:.cpp=)

all : $(EXECUTABLES)

$(EXECUTABLES): %: %.cpp
	$(CC) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(EXECUTABLES)
