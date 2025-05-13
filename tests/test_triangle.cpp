#include "../include/shapes.hpp"
#include "../include/draw.hpp"
#include <iostream>
#include <vector>
#include "tests_helpers.hpp"

int main()
{
    // ───────────────────────────────────────────────────────────────────────
    // 1. 3-4-5 right-angled triangle  (A≡(0,0), B≡(3,0), C≡(0,4))
    // ───────────────────────────────────────────────────────────────────────
    Triangle t(Point(0,0), Point(3,0), Point(0,4));

    // geometry
    assert( almost(t.perimeter(), 12.0) );
    assert( almost(t.area(),       6.0) );
    Point g = t.center();                       // centroid
    assert( almost(g.x, 1.0) && almost(g.y, 4.0/3.0) );

    // shape predicates
    assert(  t.isRightAngled() );
    assert( !t.isIsoceles()    );
    assert( !t.isEquilateral() );

    // in-circle
    {
        Circle inc = t.inscribedCircle();
        assert( almost(inc.radius, 1.0) );
        assert( almost(inc.center.x, 1.0) && almost(inc.center.y, 1.0) );
    }

    // circum-circle
    {
        Circle crc = t.circumscribedCircle();
        assert( almost(crc.radius, 2.5) );
        assert( almost(crc.center.x, 1.5) && almost(crc.center.y, 2.0) );
    }

    // equals()
    Triangle same   = t;          // copy-constructed identical triangle
    Triangle other(Point(0,0), Point(1,0), Point(0,1));
    assert(  t.equals(same)  );
    assert( !t.equals(other) );

    // ───────────────────────────────────────────────────────────────────────
    // 2. translate  by (+1 , +2)
    // ───────────────────────────────────────────────────────────────────────
    t.translate( Point(1,2) );
    Point g2 = t.center();
    assert( almost(g2.x, 2.0) && almost(g2.y, 10.0/3.0) );
    assert( almost(t.area(), 6.0) );          // area invariant
    assert( almost(t.perimeter(), 12.0) );    // perimeter invariant

    // ───────────────────────────────────────────────────────────────────────
    // 3. resize ×2 (about centroid)
    // ───────────────────────────────────────────────────────────────────────
    t.resize(2.0);
    Point g3 = t.center();
    assert( almost(g3.x, g2.x) && almost(g3.y, g2.y) );   // centre fixed
    assert( almost(t.perimeter(), 24.0) );
    assert( almost(t.area(),      24.0) );

    // side length doubled?  check AB
    const double ab_len = t.A.distance(t.B);
    assert( almost(ab_len, 6.0) );            // was 3, now 6

    // ───────────────────────────────────────────────────────────────────────
    // 4. rotate +90° (π/2 rad) about centroid
    // ───────────────────────────────────────────────────────────────────────
    const double before_AB = t.A.distance(t.B);
    t.rotate(M_PI / 2.0);

    // centre unchanged, side lengths unchanged
    Point g4 = t.center();
    assert( almost(g4.x, g3.x) && almost(g4.y, g3.y) );
    assert( almost(t.A.distance(t.B), before_AB) );
    assert( almost(t.area(),      24.0) );
    assert( almost(t.perimeter(), 24.0) );

    // ───────────────────────────────────────────────────────────────────────
    // 5. equilateral triangle tests
    // ───────────────────────────────────────────────────────────────────────
    const double h = std::sqrt(3.0) / 2.0;
    Triangle eq(Point(0,0), Point(1,0), Point(0.5, h));
    assert(  eq.isEquilateral() );
    assert(  eq.isIsoceles()    );
    assert( !eq.isRightAngled() );

    Circle inc_eq = eq.inscribedCircle();
    assert( almost(inc_eq.center.x, 0.5) );
    assert( almost(inc_eq.center.y, h/3.0) );
    assert( almost(inc_eq.radius,   h/3.0) );

    std::cout << "All Triangle tests passed ✓\n";
}