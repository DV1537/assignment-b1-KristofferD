#ifndef FIGURE_H
#define FIGURE_H
#include "shape.h"

class Figure
{
public:
	Figure();
	~Figure();
	bool addShape(Shape s);
	void getBoundingBox() const;
private:
	Shape *shapesArr;
	void expandArray();
	unsigned int nrOfShapes;
	unsigned int arrSize;
};


#endif // !FIGURE_H
