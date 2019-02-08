#include "main.h"
#include "point.h"
#include "shape.h"


  Point::Point(float x, float y){
    
  this->verticies[0] = x;
  this->verticies[1] = y;
  };
  

  float Point::area() const
  {
    return -1.0;
  };


  string Point::getType()
  {
	  return "Point";
  };


  float Point::circumference()const {
    return -1;
  };

  string Point::position() const{
	  string p = to_string(verticies[0]) + ' ' + to_string(verticies[1]);
    return p;
  };


  bool Point::isConvex()const {
    return false;
  };


float Point::distance(Shape *s)const{
std::string tempCenter = s->position();
std::string::size_type sz;
float x = std::stof (tempCenter,&sz);
float y = std::stof (tempCenter.substr(sz));
x = fmax(x,verticies[0]) - fmin(x,verticies[0]);
x *= x; //x = pow(x, 2);
y = fmax(y,verticies[1]) - fmin(y,verticies[1]);
y *= y; //y = pow(y, 2);
float distance = x + y;
distance = sqrt(distance);
  return distance;
}
Point::~Point()
{
}
int Point::getNrOfVerticies() const
{
	return 1;
}
bool Point::operator==(Point & other)
{
	if (other.getType() != this->getType()
	{
		return false;
	}
	else if (position() != other.position()) {
		return false;
	}
	else if(getCordinates(0) == other.getCordinates(0) && getCordinates(1) == other.getCordinates(1))
	{
		return true;
	}
	return false;
};
