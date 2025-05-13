#include "point.hpp"
#include "shapes/circle.hpp"
#include <cmath>
#include <numbers>
#include <print>
#include "draw.hpp"

using namespace std; 

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference() {
	return 2 * numbers::pi * radius; //formule du périmètre d'un disque
}

double Circle::area() {
	return numbers::pi * radius * radius; //formule de l'aire d'un disque 
}

void Circle::draw() {
	vector<Point>points; // on crée un vecteur de points pour stocker les points de coordonnées différentes
    for(int i = 0 ; i<360; i++) { // on va faire varier un angle i pour tracer tous les points qui formeront le cercle
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


bool Circle::equals(Circle circle){
    return(radius==circle.radius)&&(center.x==circle.center.x && center.y==circle.center.y);
}

