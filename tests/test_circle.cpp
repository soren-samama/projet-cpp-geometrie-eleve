#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>
#include "tests_helpers.hpp"
#include <cassert>
#include <cmath>
<<<<<<< HEAD

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
=======
>>>>>>> 0012eeff01df1c50347711c53b100c45c413a864

int main() {
    Circle c(10.0, Point(5.0, 3.0));

    assert( almost(c.circumference(), 2 * M_PI * 10.0) );
    assert( almost(c.area(),          M_PI * 100.0)   );

    c.translate( Point(4.0, -1.0) );
    assert( almost(c.center.x, 9.0) );
    assert( almost(c.center.y, 2.0) );

    c.resize(0.5);
    assert( almost(c.radius, 5.0) );
    assert( almost(c.circumference(), 2 * M_PI * 5.0) );
    assert( almost(c.area(),          M_PI * 25.0)    );

    Circle same(5.0, Point(9.0, 2.0));
    Circle different(5.1, Point(9.0, 2.0));
    assert(  c.equals(same)      );
    assert( !c.equals(different) );

    std::cout << "All Circle tests passed ✓\n";
}