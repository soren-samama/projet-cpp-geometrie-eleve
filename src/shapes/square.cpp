#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <stdio.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){ //return length of a side 
    if (A.x > C.x) {
        return A.x-C.x;
    } else {
        return C.x - A.x;
    }
}

double Square::perimeter(){  //return perimeter of a square
    return 4 * side();
}

double Square::area(){  //return area of a square
    return side() * side();
}

Point Square::center(){  //return coordonates of the center of the square
    double l = side()/2;
    return Point(std::max(A.x,C.x)-l,std::max(A.y,C.y)-l); 
}


//Function to rotate a point based on the angle if the square is rotated
//used in draw()
Point rotate_point(Point p, Point center_point, double cos_theta, double sin_theta) {
    double dx = p.x - center_point.x;
    double dy = p.y - center_point.y;

    double x_new = cos_theta * dx - sin_theta * dy + center_point.x;
    double y_new = sin_theta * dx + cos_theta * dy + center_point.y;

    return Point(x_new, y_new);
};


void Square::draw() { //draw square on screen based on the center of the square
    Point center_point = center();

    double s = side(); 
    double half_s = s / 2;

    //Getting the coordonates of each corner
    Point top_left(center_point.x - half_s, center_point.y + half_s);
    Point top_right(center_point.x + half_s, center_point.y + half_s);
    Point bottom_right(center_point.x + half_s, center_point.y - half_s);
    Point bottom_left(center_point.x - half_s, center_point.y - half_s);

    //Getting every angle if the square is rotated
    double angle_rad = std::atan2(C.y - A.y, C.x - A.x) - M_PI / 4; 
    double cos_theta = std::cos(angle_rad);
    double sin_theta = std::sin(angle_rad);

    //Vector with the coordonates of every point
    std::vector<Point> rotated_points = {
        rotate_point(top_left, center_point, cos_theta, sin_theta),
        rotate_point(top_right, center_point, cos_theta, sin_theta),
        rotate_point(bottom_right, center_point, cos_theta, sin_theta),
        rotate_point(bottom_left, center_point, cos_theta, sin_theta),
        rotate_point(top_left, center_point, cos_theta, sin_theta)
    };
    
    //drawing the square
    draw_picture(rotated_points);
}


void Square::translate(Point T) {
    A.x += T.x;
    A.y += T.y;
    C.x += T.x;
    C.y += T.y;
}

//resize a square by keeping the same center
void Square::resize(double ratio) {
    Point center_point = center();

    double half_new_side = side() * ratio / 2;

    A.x = center_point.x - half_new_side;
    A.y = center_point.y - half_new_side;
    C.x = center_point.x + half_new_side;
    C.y = center_point.y + half_new_side;
}

//rotate a square with a given angle in degree
void Square::rotate(double angle) {
    Point center_point = center();

    //Getting every angle
    double angle_rad = angle * M_PI / 180.0;
    double cos_theta = std::cos(angle_rad);
    double sin_theta = std::sin(angle_rad);

    //Building vector of non-rotated points and creating one for rotated points
    Point B(A.x, C.y);
    Point D(C.x, A.y);
    Point points[4] = {A, B, C, D};
    Point rotated[4];

    //rotating every point with the right angle
    for (int i = 0; i < 4; ++i) {
        double dx = points[i].x - center_point.x;
        double dy = points[i].y - center_point.y;

        double x_new = cos_theta * dx - sin_theta * dy + center_point.x;
        double y_new = sin_theta * dx + cos_theta * dy + center_point.y;

        rotated[i] = Point(x_new, y_new);
    }

    //Updating the coordonates
    A = rotated[0];
    C = rotated[2]; 
}


//Comparing if 2 square are the same by comparing their sides lenght
bool Square::equals(Square square) {
    double epsilon = 1e-6; //error margin with decimal number
    return std::abs(side() - square.side()) < epsilon;
}


//Drawing inscribed Circle
Circle Square::inscribedCircle() {
    Point center_point = center();
    double radius = side() / 2.0;
    return Circle(radius, center_point);
}


//Drawing circumscribed Circle
Circle Square::circumscribedCircle() {
    Point center_point = center();
    double radius = (side() * std::sqrt(2)) / 2.0;
    return Circle(radius, center_point);
}