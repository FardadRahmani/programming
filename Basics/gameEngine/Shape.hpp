// Vector3.h
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
	Shape() = default;
	Shape(float x, float y, float z) { mPosition.mX = x; mPosition.mY = y; mPosition.mZ = z;}
	virtual string type()=0;
	

protected:
	Vector3 mPosition;
	string mName;
	


};


#endif // SHAPE_H

