#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>


int main() {
	
	Square square(Point(0, 0), Point(1, 1));
	square.draw();
	
	return 0;
}
