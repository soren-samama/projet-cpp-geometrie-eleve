#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>
#include "../include/tests_helpers.hpp"
#include <cassert>

int main() 
{
    Square s(Point(0, 0), Point(10, 10));
    assert( almost(s.side(),      10.0) );
    assert( almost(s.perimeter(), 40.0) );
    assert( almost(s.area(),     100.0) );
    assert( almost(s.center(),   Point(5,5)) );

    s.translate(Point(3, -2));
    assert( almost(s.center(), Point(8, 3)) );
    assert( almost(s.side(), 10.0) );          // translating must not change size

    s.resize(2.0);
    assert( almost(s.side(),      20.0) );
    assert( almost(s.perimeter(), 80.0) );
    assert( almost(s.area(),     400.0) );
    assert( almost(s.center(),   Point(8,3)) );

    assert( almost(s.A, Point(-2, -7)) );
    assert( almost(s.C, Point(18, 13)) );

    s.rotate(90);
    assert( almost(s.side(), 20.0) );          // rotation must not change size
    assert( almost(s.center(), Point(8,3)) );

    assert( almost(s.A, Point(18, -7)) );
    assert( almost(s.C, Point(-2, 13)) );

    Square same(Point(s.A.x, s.A.y), Point(s.C.x, s.C.y));
    Square different(Point(0,0), Point(1,1));

    assert(s.equals(same));    
    assert(!s.equals(different));

    std::cout << "All Square tests passed";
}