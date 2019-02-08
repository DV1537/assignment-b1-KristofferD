#include "figure.h"
#include "Polygon.h"
Figure::Figure()
{
	nrOfShapes = 0;
	arrSize = 0;
	shapesArr = new Shape[arrSize];
}

Figure::~Figure()
{
}

bool Figure::addShape(Shape s)
{
	for (int i = 0; i < nrOfShapes; i++) {
		if (s == shapes[i]{
			return false;
		}
	}

	if (nrOfShapes >= arrSize)
		Shape tempArr = new Shape[arrSize + 5];
	for(int i = 0; i < arrSize)
	{
		tempArr[i] = shapeArr[i];
	}
	delete[] shapeArr;
	shapesArr = tempArr;
	arrSize+= 5;

	shapeArr[nrOfShapes] = s;
	nrOfShapes++;
	return true;
}

void Figure::getBoundingBox() const
{
	float maxX = shapesArr[0].getCordinates(0);
	float minX = maxX;
	float maxY = shapesArr[0].getCordinates(1);
	float minY = maY;
	float tempCord;
	for(int i = 0; i < nrOfShapes; i++){
		for (int j = 0; j < shapesArr[i].getNrOfVerticies(); j++) {
			tempCord = shapesArr[i].getCordinates(j);
			if (j % 2 == 0)
			{
				if (maxX < tempCord)
				{
					maxX = tempCord;
				}
				else if (minX > tempCord) {
					minX = tempCord;
				}
			}
			else {
				if (maxY < tempCord) {
					maxY = tempCord;
				}
				else if (minY > tempCord) {
					minY = tempCord;
				}
			}


		}
		
		
		
	}
}
