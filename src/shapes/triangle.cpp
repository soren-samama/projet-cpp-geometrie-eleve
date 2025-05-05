#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <vector>

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimetre (){

    double AB,BC,CA;

    AB = sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
    BC = sqrt(pow(C.x-B.x,2)+pow(C.y-B.y,2));
    CA = sqrt(pow(A.x-C.x,2)+pow(A.y-C.y,2));

    return AB + BC + CA;

}

double Triangle::area(){

    return 0.5 * ( A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y) ) ;

}

Point Triangle::center(){

    double Gx,Gy;

    Gx = (A.x + B.x + C.x)/3;
    Gy = (A.y + B.y + C.y)/3;

    return Point(Gx,Gy);

}

void Triangle::draw(){

    std::vector<point> points = {A,B,C,A};

    draw_pictures(points);

}

