#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <string>
using namespace std;

class Line: public Shape{
public:
  Line(float x1, float y1, float x2, float y2);
  ~Line();
  string getType();
  float area() const;
  float circumference() const;
  string position() const;
  bool isConvex() const;
  float distance(Shape *s) ;
  Line operator=(const Line& other);
  ostream & operator<<(ostream & other);
  int getNrOfVerticies() const;
  bool operator==(const Line& other);

private:
  float verticies[6];
  float getCordinates(int cordinate);
  float distanceOfPoints(float x1, float x2, float y1, float y2);
}




#endif
