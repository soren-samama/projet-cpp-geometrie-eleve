#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <numbers>
#include <print>
#include "draw.hpp"

using namespace std; 

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference() {
	return 2 * numbers::pi * radius; 
}

double Circle::area() {
	return numbers::pi * radius * radius; 
}

void Circle::draw() {
	vector<Point>points; 
    for(int i = 0 ; i<360; i++) { 
        double angle = i * numbers::pi / 180; 
        double x = center.x + radius * cos(angle);
        double y = center.y + radius * sin(angle);
        points.push_back(Point(x,y)); 
    }
	draw_picture(points); 
}

void Circle::translate(Point T) { 
    center.x = T.x + center.x; 
    center.y = T.y + center.y; 
}


void Circle::resize(double ratio) { 
    radius = radius * ratio;
}


/*bool Circle::equals(Circle circle){ // to do : precision error 
    return(radius==circle.radius)&&(center.x==circle.center.x && center.y==circle.center.y); 
}*/

bool Circle::equals(Circle circle) {
    // Définir une petite tolérance (epsilon) pour la comparaison des flottants
    const float epsilon = 1e-6;

    // Comparaison des rayons avec tolérance
    bool radiusEqual = abs(radius - circle.radius) < epsilon;

    // Comparaison des centres avec tolérance
    bool centerEqual = abs(center.x - circle.center.x) < epsilon && abs(center.y - circle.center.y) < epsilon;

    return radiusEqual && centerEqual;
}