#include "line.h"
#include "main.h"
#include "shape.h"

Line::Line(float x1, float y1, float x2, float y2){
  this->verticies[0] = x1;
  this->verticies[1] = y1;
  this->verticies[2] = x2;
  this->verticies[3] = y2;
}
Line::~Line()
{
}
float Line::circumference() const{return -1;};
string Line::getType() {return "Line";};
float Line::area() const{return -1;};

string Line::position() const{
  float x = (verticies[0] + verticies[2])/2.0;
  float y = (verticies[1] + verticies[3])/2.0;
  string xAndY = to_string(x) + " " + to_string(y);
  return xAndY;
};

bool Line::isConvex() const{
	return false;
};


float Line::distance(Shape *s){
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
Line Line::operator=(const Line& other)
{
	return *this;
}
ostream & Line::operator<<(ostream & other)
{
	//Check function and fix string stream
}
int Line::getNrOfVerticies() const
{
	return 2;
}
bool Line::operator==(const Line & other)
{
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



float Line::getCordinates(int cordinate){
	if (cordinate >= getNrOfVerticies())
	{
		return verticies[cordinate % getNrOfVerticies()]
	}
	else if (crodinate < 0) {
		return NULL;
	else return verticies[cordinate];
};


float Line::distanceOfPoints(float x1, float x2, float y1, float y2){
  float x = x1 > x2 ? x1 - x2 : x2 - x1;
  x *= x; //x = pow(x, 2);
  float y = y1 > y2 ? y1 - y2 : y2 - y1;
  y *= y; //y = pow(y, 2);
  float distance = sqrt(x + y);
    return distance;
};