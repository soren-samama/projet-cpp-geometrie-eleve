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

void Triangle::translate(){
    
    B = Point( B.x + (T.x-A.x) , B.y + (T.y-A.y) )
    C = Point( C.x + (T.x-A.x) , C.y + (T.y-A.y) ) 
    A = T;

}

void Triangle::resize(){

    Point G = Triangle::center();

    A = Point( G.x + ratio * (A.x - G.x) , G.y + ratio * (A.y - G.y) );
    B = Point( G.x + ratio * (B.x - G.x) , G.y + ratio * (B.y - G.y) );
    C = Point( G.x + ratio * (C.x - G.x) , G.y + ratio * (C.y - G.y) );

}

