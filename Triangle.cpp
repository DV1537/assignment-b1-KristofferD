#include "Triangle.h"
#include "main.h

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3){
verticies = new float[6]{x1, y1, x2, y2, x3, y3};
};

Triangle::~Triangle() { delete verticies; };

float Triangle::area() const{
//Heron's formula
float a, b, c, s, o;
a=distanceOfPoints(verticies[0], verticies[2], verticies[1],verticies[3]);
b=distanceOfPoints(verticies[2], verticies[4], verticies[3],verticies[5]);
c=distanceOfPoints(verticies[0], verticies[4], verticies[1],verticies[5]);
s=(a+b+c)/2.0;
o = std::abs(std::sqrt((s*(s - a)*s - b)*s - c));
return o;
};


string Triangle::getType() {return "Triangle";};

float Triangle::distanceOfPoints(float x1, float x2, float y1, float y2) const{
  float x = std::abs(x1 - x2);
  x *= x; //x = pow(x, 2);
  float y = std::abs(y1 - y2);
  y *= y; //y = pow(y, 2);
  float distance = sqrt(x + y);
    return distance;
}
int Triangle::getNrOfVerticies() const
{
	return 3;
}
;

float Triangle::circumference() const {
	float circ = 0.0;
	for (int i = 0; i < 5; i += 2)
	{
		if (i == 5) {
			circ += distanceOfPoints(verticies[4], verticies[0], verticies[5], verticies[1]);
		}
		else
			circ += distanceOfPoints(verticies[i], verticies[i + 2], verticies[i + 1], verticies[i + 3]);
	};
}

string Triangle::position() const{
  float x = (verticies[0] + verticies[2] + verticies[4])/3.0;
  float y = (verticies[1] + verticies[3] + verticies[5])/3.0;
  string xAndY = to_string(x) + " " + to_string(y);
  return xAndY;
}
bool Triangle::isConvex() const
{
	return false;
};

float Triangle::distance(Shape *s) const{
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
bool Triangle::operator==(Triangle & other) {
	if (other.getType() != this->getType()
	{
		return false;
	}
	else if (other.area() != this.area()) {
		return false;
	}
	else if (position() != other.position()) {
		return false;
	}
	else {
		for (int i = 0; i < getNrOfVerticies; i++) {
			for (int j = 0; j < getNrOfVerticies; j++) {
				if (this->getCordinates(i) = other.getCordinates(j)) {
					for (int k = 0; k < getNrOfVerticies(); k++) {
						if (this->getCordinates(k + i) != other.getCordinates(k + j) {
							return false;
						}
					}
				}

			}
		}
		return true;
	}
	return false;
};

float Triangle::getCordinates(int cordinate) const {return verticies[cordinate];}
