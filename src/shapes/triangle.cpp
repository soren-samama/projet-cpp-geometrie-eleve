#include "point.hpp"
#include "draw.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include <vector>

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter (){

    double AB,BC,CA;

    AB = sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2)); // calul longeure chaque côté
    BC = sqrt(pow(C.x-B.x,2)+pow(C.y-B.y,2));
    CA = sqrt(pow(A.x-C.x,2)+pow(A.y-C.y,2));

    return AB + BC + CA; // somme des trois côtés

}

double Triangle::area(){

    return 0.5 * ( A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y) ) ; // formule de l'aire avec les coordonnées des points d'un triangle

}

Point Triangle::center(){

    double Gx,Gy;

    Gx = (A.x + B.x + C.x)/3; // formule du x du centre de gravité d'un tiangle avec les x des 3 points de ce triangle 
    Gy = (A.y + B.y + C.y)/3; // formule du y du centre de gravité d'un tiangle avec les y des 3 points de ce triangle

    return Point(Gx,Gy);

}

void Triangle::draw(){

    std::vector<Point> points = {A,B,C,A}; // créé veteur des points du triangle 

    draw_picture(points); // dessine une droite entre chaque point du vecteur

}

void Triangle::translate(Point T){
    
    B = Point( B.x + (T.x-A.x) , B.y + (T.y-A.y) ); // add diff entre T et A à B puis redéfini B
    C = Point( C.x + (T.x-A.x) , C.y + (T.y-A.y) ); // add diff entre T et A à C puis redéfini C
    A = T; // défini A comme T

}

void Triangle::resize(double ratio){

    Point G = Triangle::center(); // donne le centre de gravité du triangle et le stock dans G

    A = Point( G.x + ratio * (A.x - G.x) , G.y + ratio * (A.y - G.y) ); // formule pour multiplier par un certain ratio les distances centre de gravité - A
    B = Point( G.x + ratio * (B.x - G.x) , G.y + ratio * (B.y - G.y) ); // formule pour multiplier par un certain ratio les distances centre de gravité - B
    C = Point( G.x + ratio * (C.x - G.x) , G.y + ratio * (C.y - G.y) ); // formule pour multiplier par un certain ratio les distances centre de gravité - C

}

bool Triangle::equals(Triangle t){
    //TODO verifier tt 6 permutations pr egaliter des deux triangles
}