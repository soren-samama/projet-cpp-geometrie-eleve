CXX = g++
CXXFLAGS = -std=c++23 -I../include

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

SRC_DIR = ../src
TEST_DIR = .
TESTS = test_circle test_square test_triangle test_all_shapes

.PHONY: all clean

all: $(TESTS)

# Rules for test compilation
test_circle: $(TEST_DIR)/test_circle.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRC_DIR)/*.cpp $(SRC_DIR)/shapes/*.cpp $(LDFLAGS)

test_square: $(TEST_DIR)/test_square.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRC_DIR)/*.cpp $(SRC_DIR)/shapes/*.cpp $(LDFLAGS)

test_triangle: $(TEST_DIR)/test_triangle.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRC_DIR)/*.cpp $(SRC_DIR)/shapes/*.cpp $(LDFLAGS)

test_all_shapes: $(TEST_DIR)/test_all_shapes.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(SRC_DIR)/*.cpp $(SRC_DIR)/shapes/*.cpp $(LDFLAGS)

clean:
	rm -f $(TESTS) 