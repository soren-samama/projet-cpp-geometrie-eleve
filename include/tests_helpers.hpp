#ifndef TESTS_HELPERS
#define TESTS_HELPERS

#include <iostream>
#include "./shapes/point.hpp"

constexpr double EPS = 1e-9;

bool almost(double a, double b, double eps = EPS);

bool almost(const Point& p, const Point& q, double eps = EPS);

#endif