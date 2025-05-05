CXX = g++
CXXFLAGS = -std=c++23 -Iinclude

# Detect operating system
ifeq ($(OS),Windows_NT)
    LDFLAGS = -lgdi32 -luser32
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CXXFLAGS += -I/opt/X11/include
        LDFLAGS = -L/opt/X11/lib -lX11
    endif
endif

SRC = src/*.cpp src/shapes/*.cpp main.cpp

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)

clean:
	rm -f main