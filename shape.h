#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape{
public:
  Shape();
  ~Shape();
  virtual string getType() = 0;
  float area() const;
  float circumference() const;
  string position() const;
  bool isConvex() const;
  float distance(Shape *s) const;
  float distanceOfPoints(float x1, float x2, float y1, float y2);
  int getNrOfVerticies() const;
private:
};


#endif
