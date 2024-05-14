// Vector3.h
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include "Vector3.hpp"
using namespace std;

class Shape
{
public:
	Shape() = default;
	Shape(float x, float y, float z) { mPosition.mX = x; mPosition.mY = y; mPosition.mZ = z; ++shapeCounter; }
	virtual string type()=0;
	/*void move(float x, float y, float z ) {
		mPosition.mX = x;
		mPosition.mY = y;
		mPosition.mZ = z;
	};*/
	static int shapeCounter;
	void printPos() {	cout << "<PositionXYZ:" << mPosition.mX << ", " << mPosition.mY << ", " << mPosition.mZ << "> \n";}
	void inputPos()	{	cout << "Enter x: "; cin >> mPosition.mX;    cout << "Enter y: ";cin >> mPosition.mY;  	cout << "Enter z: ";cin >> mPosition.mZ;}
	
protected:
	Vector3 mPosition;
	string mName;
	

	
};


#endif // SHAPE_H

