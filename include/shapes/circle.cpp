#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(double r, Point c) : radius(r), center(c) {}

double Circle::circumference() {
	return 2 * M_PI * radius;
}

double Circle::area() {
	return M_PI * radius * radius;
}

void Circle::draw() {
    int i = 0;
    while (i < 360) {
        double angle = i * M_PI / 180;
        double x = center.x + radius * cos(angle);
        double y = center.y + radius * sin(angle);
        print(Circle.push_back(Point(x, y)));
    }
}

void Circle::translate(Point T) {
    C.x = T.x + center.x; 
    C.y = T.y + center.y;
}


void Circle::resize(double ratio) {
    radius = radius * ratio;
}

bool Circle::equals(Circle circle) {
    radius = circle.radius;
    center = circle.center;
    return radius && center; 
}
