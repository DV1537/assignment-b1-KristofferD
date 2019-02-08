#include "shape.h"
#include "main.h"


Shape::Shape(){
};
Shape::~Shape(){};
float Shape::area() const { return -1; };
float Shape::circumference() const { return -1; };
string Shape::position() const { return ""; };
bool Shape::isConvex() const { return false; };
float Shape::distance(Shape *s) const { return 0.0; }
float Shape::distanceOfPoints(float x1, float x2, float y1, float y2)
{
	return 0.0f;
}