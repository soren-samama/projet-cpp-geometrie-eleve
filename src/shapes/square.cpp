#include "point.hpp"
#include "shapes/square.hpp"

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
    return Point(max(A.x,C.x)-l,max(A.y,C.y)-l); 
}

void Square::draw(){  //draw the square on the screen at coordonates 0,0
    
}