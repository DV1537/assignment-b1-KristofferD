#ifndef POINT_H
#define POINT_H
#include<string>
#include "shape.h"

using namespace std;

class Point : public Shape {
public:
	Point(float x1, float y1);
	float area() const;
	string getType();
	float circumference() const;
	string position() const;
	bool isConvex() const;
	float distance(Shape *s) const;
	~Point();
	int getNrOfVerticies() const;
	bool operator==(Point& other);
private:
	float verticies[2];
}
#endif;
