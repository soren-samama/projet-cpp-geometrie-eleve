#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Testing Triangle class" << std::endl;
    
    Triangle triangle(Point(150, 50), Point(250, 200), Point(50, 200));
    
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: (" << triangle.a.x << ", " << triangle.a.y << ")" << std::endl;
    std::cout << "B: (" << triangle.b.x << ", " << triangle.b.y << ")" << std::endl;
    std::cout << "C: (" << triangle.c.x << ", " << triangle.c.y << ")" << std::endl;
    std::cout << "Triangle area: " << triangle.area() << std::endl;
    std::cout << "Triangle perimeter: " << triangle.perimeter() << std::endl;
    
    std::vector<Point> points = triangle.getPoints();
    std::cout << "Drawing triangle with " << points.size() << " points" << std::endl;
    draw_picture(points);
    
    return 0;
} 