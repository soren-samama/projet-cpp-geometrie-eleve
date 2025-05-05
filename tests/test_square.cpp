#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Testing Square class" << std::endl;

    Square square(Point(200, 200), 100);
    
    std::cout << "Square center: (" << square.center.x << ", " << square.center.y << ")" << std::endl;
    std::cout << "Square side length: " << square.side << std::endl;
    std::cout << "Square area: " << square.area() << std::endl;
    std::cout << "Square perimeter: " << square.perimeter() << std::endl;
    
    std::vector<Point> points = square.getPoints();
    std::cout << "Drawing square with " << points.size() << " points" << std::endl;
    draw_picture(points);
    
    return 0;
} 