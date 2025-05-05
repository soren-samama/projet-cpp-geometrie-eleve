#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <stdio.h>

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){ //return length of a side 
    if (A.x > C.x) {
        return A.x-C.x;
    } else {
        return C.x - A.x;
    }
}

double Square::perimeter(){  //return perimeter of a square
    return 4 * Square.side();
}

double Square::area(){  //return area of a square
    return Square.side() * Square.side();
}

Point Square::center(){  //return coordonates of the center of the square
    double l = Square.side()/2;
    return Point(std::max(A.x,C.x)-l,std::max(A.y,C.y)-l); 
}

void Square::draw(){  //draw the square on the screen at coordonates 0,0
    A1 = Point(A.x+Square.side(), A.y);
    C1 = Point(C.x-Square.side(), C.y);
    std::vector<Point> points = {A, A1, C, C1, A};
    draw_picture(points);
}

void Square::translate(Point T){
    A = T;
}