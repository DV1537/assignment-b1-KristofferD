#include "polygon.h"
#include "main.h"

Polygon::Polygon(int nrOfVerticies, float *arr[]){
  this->verticies = new float[nrOfVerticies];
};
Polygon::~Polygon() { delete verticies; };
string Polygon::getType(){
  return "Polygon";
};
float Polygon::area() const{
  float area = 0.0;
  int i = 0;
  while(i < nrOfVerticies *2){
      area += verticies[i]*verticies[i+2]+verticies[i+1]*verticies[i+3];
    i+= 2;
  }
area += verticies[i]*verticies[1]+verticies[i+1]*verticies[0];
area /= 2.0;
return area; //Will be false if the polygon is self intersecting.
};
float Polygon::circumference() const{
int i = 0;
float circ = 0.0;
while(i < nrOfVerticies){
  circ += distanceOfPoints(verticies[i], verticies[i+2], verticies[i+1], verticies[i+3]);
  i+2;
}
  circ += distanceOfPoints(verticies[i], verticies[0], verticies[i+1], verticies[1]);
  return circ;
}
float Polygon::getCordinates(int cordinate)
{
	return verticies[cordinate];
}
float Polygon::distanceOfPoints(float x1, float x2, float y1, float y2)const
{
	float a = x1 > x2 ? x1 - x2 : x2 - x1;
	a *= a;
	float b = y1 > y2 ? y1 - y2 : y2 - y1;
	b *= b;
	return sqrtf(a + b);
};


string Polygon::position() const{
float minY = verticies[1];
float maxY = verticies[1];
float minX = verticies[0];
float maxX = verticies[0];
for(int i = 2; i < nrOfVerticies; i + 2)
{
  if(minY > verticies[i+1]){minY = verticies[i+1];}
  else if(maxY < verticies[i+1]){maxY = verticies[i+1];}

  if (minX > verticies[i]){minX = verticies[i];}
  else if(maxX < verticies[i]){maxX = verticies[i];}
  }
float centerX = minX +((maxX - minX)/2.0);
float centerY = minY +((maxY - minY)/2.0);
string center = to_string(centerX) + "" + to_string(centerY);
return center;
}

bool Polygon::isConvex() const{ //https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex
  //False positive if self-intersecting.
	if (nrOfVerticies < 4) return true;
     bool sign = false;

     for(int i = 0; i < nrOfVerticies; i++)
     {
         float dx1 = verticies[i];
         float dy1 = verticies[i +1];
         float dx2 = verticies[i+2];
         float dy2 = verticies[i+3];
         float zcrossproduct = dx1 * dy2 - dy1 * dx2;

         if (i == 0)
             sign = zcrossproduct > 0;
         else if (sign != (zcrossproduct > 0))
             return false;
     }
	 return false;
 }


float Polygon::distance(Shape *s) const{
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
int Polygon::getNrOfVerticies() const
{
	return nrOfVerticies;
}
bool Polygon::operator==(Polygon & other) const
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
