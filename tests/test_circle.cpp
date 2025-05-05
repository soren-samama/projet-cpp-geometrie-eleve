#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Testing Circle class" << std::endl;
    
    Circle circle(100, Point(150, 150));
    
    std::cout << "Circle center: (" << circle.center.x << ", " << circle.center.y << ")" << std::endl;
    std::cout << "Circle radius: " << circle.radius << std::endl;
    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Circle circumference: " << circle.circumference() << std::endl;
    
    circle.draw();
    
    return 0;
} 