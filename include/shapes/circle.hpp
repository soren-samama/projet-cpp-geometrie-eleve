#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"

struct Circle {
	double radius;
	Point center;
	
	Circle(double r, Point c = Point());
	
	/** 
	* Returns the circumference of the circle
	*/
	double circumference();
	/**
	* Returns the area of the circle
	*/
	double area();
	/**
	* Draws the circle by adding points to a vector, then adding+1 for the angle to create a full circle
	* conversion from degree to radian
	*/
	void draw();
	/**
	* Translates the center to another center 
	*@param T the point used to move the center 
	*/
	void translate(Point T);
	
	/**
	 * Resize the circle from its center by a ratio.
	 * @param ratio The ratio from which to resize the circle.
	 */
	void resize(double ratio); // resize while maintaining center
	/** 
	* Compares circle with the use of epsilon to minimize the difference 
	* @param circle is the circle used for comparison 
	*/
	bool equals(Circle circle);
	
};

#endif // CIRCLE_HPP