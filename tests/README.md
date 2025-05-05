# Geometric Shapes Tests

This directory contains test files for the geometric shapes library.

## Available Tests

- `test_circle.cpp` - Tests the Circle class functionality
- `test_square.cpp` - Tests the Square class functionality  
- `test_triangle.cpp` - Tests the Triangle class functionality
- `test_all_shapes.cpp` - Demonstrates using all shapes together

## How to Compile and Run Tests

To compile all tests:

```
cd tests
make
```

To run a specific test:

```
cd tests
./test_circle     # Test the Circle class
./test_square     # Test the Square class
./test_triangle   # Test the Triangle class
./test_all_shapes # Test all shapes together
```

To clean compiled files:

```
cd tests
make clean
```

## Test Output

Each test will display information about the shape properties (area, perimeter, etc.) 
and will draw the shape using the drawing library. 