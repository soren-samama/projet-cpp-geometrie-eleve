#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <numbers>
#include <print>

using namespace std; 

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference() {
	return 2 * numbers::pi * radius;
}

double Circle::area() {
	return numbers::pi * radius * radius;
}

void Circle::draw() {
    int i = 0;
    while (i < 360) {
        double angle = i * numbers::pi / 180;
        double x = center.x + radius * cos(angle);
        double y = center.y + radius * sin(angle);
        print(Circle.push_back(Point(x, y))); // pb avec le circle.push_back
    }
}

void Circle::translate(Point T) {
    Circle.x = T.x + center.x; 
    Circle.y = T.y + center.y; // circle n'est pas défini
}


void Circle::resize(double ratio) {
    radius = radius * ratio;
}


bool Circle::equals(Circle circle){
    bool circle = false; 
    if (r!==0){
        circle = true; 
    }
     return circle; 
}