#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"

class Polygon: public Shape{
public:
  Polygon(int nrOfVerticies, float *arr[]);
  ~Polygon();
  string getType();
  float area() const;
  float circumference() const;
  string position() const;
  bool isConvex() const;
  float distance(Shape *s) const;
  int getNrOfVerticies() const;
  bool operator==(Polygon & other) const;
private:
  int nrOfVerticies;
  float *verticies;
float getCordinates(int cordinate);
float distanceOfPoints(float x1, float x2, float y1, float y2) const;
};

#endif
