# C++ Geometry Project

A C++ project for geometric shapes manipulation and visualization.

## Overview

This project provides a framework for creating, manipulating, and visualizing geometric shapes in 2D space. It includes implementations for basic shapes such as:

- Points
- Triangles
- Circles
- Squares

Each shape supports various operations like translation, rotation, resizing, and drawing.

## Features

- **Shape Creation**: Create points, triangles, circles, and squares with custom parameters
- **Geometric Operations**: Calculate perimeter, area, and other geometric properties
- **Spatial Transformations**: Translate, rotate, and resize shapes
- **Visualization**: Draw shapes using the CTurtle library (a C++ wrapper for Python's turtle graphics)
- **Shape Analysis**: Determine properties such as whether a triangle is right-angled, equilateral, or isosceles

## Requirements

- C++23 compatible compiler (g++ recommended)
- X11 libraries (on macOS/Linux)
- GDI32 and User32 libraries (on Windows)

## Building

To build the project:

```bash
make
```

## Running

To run the example program:

```bash
make run
```

Or directly:

```bash
./main
```

## Example

```cpp
#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>

int main() {
    Triangle t(Point(0, 0), Point(100, 0), Point(50, 100));
    t.draw();
    return 0;
}
```

This example creates a triangle and draws it on screen. 