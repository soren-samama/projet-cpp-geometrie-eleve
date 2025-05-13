#include <iostream>
#include <cmath>
#include "tests_helpers.hpp"
#include "point.hpp"

bool almost(double a, double b, double eps) {
    return std::fabs(a - b) < eps;
}

bool almost(const Point& p, const Point& q, double eps) {
    return almost(p.x, q.x, eps) && almost(p.y, q.y, eps);
}