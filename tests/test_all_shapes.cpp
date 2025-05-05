#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Testing all shapes together" << std::endl;
    
    Circle circle(Point(150, 150), 50);
    Square square(Point(150, 150), 80);
    Triangle triangle(Point(150, 50), Point(200, 200), Point(100, 200));
    
    std::vector<Point> allPoints;
    
    std::vector<Point> circlePoints = circle.getPoints();
    std::cout << "Added " << circlePoints.size() << " points for the circle" << std::endl;
    allPoints.insert(allPoints.end(), circlePoints.begin(), circlePoints.end());
    
    allPoints.push_back(Point(-1000, -1000));
    
    std::vector<Point> squarePoints = square.getPoints();
    std::cout << "Added " << squarePoints.size() << " points for the square" << std::endl;
    allPoints.insert(allPoints.end(), squarePoints.begin(), squarePoints.end());
    
    allPoints.push_back(Point(-1000, -1000));
    
    std::vector<Point> trianglePoints = triangle.getPoints();
    std::cout << "Added " << trianglePoints.size() << " points for the triangle" << std::endl;
    allPoints.insert(allPoints.end(), trianglePoints.begin(), trianglePoints.end());
    
    std::cout << "Drawing all shapes with a total of " << allPoints.size() << " points" << std::endl;
    draw_picture(allPoints);
    
    return 0;
} 