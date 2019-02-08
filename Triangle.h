#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle: public Shape{
public:
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
  ~Triangle();
  float area() const;
  string getType();
  float circumference() const;
  string position() const;
  bool isConvex() const;
  float distance(Shape *s) const;
  bool operator==(Triangle& other);
private:
float *verticies;
float getCordinates(int cordinate) const;
float distanceOfPoints(float x1, float x2, float y1, float y2) const;
int getNrOfVerticies() const;
}




#endif TRIANGLE_H
